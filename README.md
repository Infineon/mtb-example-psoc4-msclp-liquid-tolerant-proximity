# PSoC&trade; 4: MSCLP CAPSENSE&trade; Liquid Tolerant Proximity Sensing

This code example demonstrates an implementation of a robust Liquid-Tolerant proximity sensing application to detect a target (a hand) at a distance of up to 35 mm. It demonstrates recommended liquid tolerance techniques and adjustments of tuning parameters. This example uses a 5th-generation low-power CAPSENSE&trade; (MSCLP) proximity widget, implemented on PSoC&trade; 4000T CAPSENSE&trade; Evaluation Kit (`CY8CKIT-040T`) to demonstrate low power mode.

This code example also demonstrates how to use a 'guard sensor' to detect the presence of liquid using the CSX sensing technique. The term **Liquid tolerance** in this case includes following scenarios only:

Scenario          | System Response  |
:-----------------| :----------------|
Small liquid droplets present on the sensing area | No reaction, system still able to sense proximity target |
Medium and large liquid droplets present on the sensing area | System goes to the liquid active state and turns OFF the proximity sensing until the liquid is removed/wiped off|
Floating Liquid flowing on the sensing area | System goes to the liquid active state and turns OFF the proximity sensing until the liquid is removed/wiped off|

The resulting solution in this implementation can effectively be called as 'Splash Proof'.


[View this README on GitHub.](https://github.com/Infineon/mtb-example-psoc4-msclp-liquid-tolerant-proximity)

[Provide feedback on this code example.](https://cypress.co1.qualtrics.com/jfe/form/SV_1NTns53sK2yiljn?Q_EED=eyJVbmlxdWUgRG9jIElkIjoiQ0UyMzgyMjgiLCJTcGVjIE51bWJlciI6IjAwMi0zODIyOCIsIkRvYyBUaXRsZSI6IlBTb0MmdHJhZGU7IDQ6IE1TQ0xQIENBUFNFTlNFJnRyYWRlOyBMaXF1aWQgVG9sZXJhbnQgUHJveGltaXR5IFNlbnNpbmciLCJyaWQiOiJtYXl1ciBjaGFuZGFrIiwiRG9jIHZlcnNpb24iOiIxLjIuMCIsIkRvYyBMYW5ndWFnZSI6IkVuZ2xpc2giLCJEb2MgRGl2aXNpb24iOiJNQ0QiLCJEb2MgQlUiOiJJQ1ciLCJEb2MgRmFtaWx5IjoiUFNPQyJ9)


## Requirements

- [ModusToolbox&trade; software](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/) v3.1 or later (tested with v3.1)
- Board support package (BSP) minimum required version: 3.1.0
- Programming language: C
- Associated parts: [PSoC&trade; 4000T]

## Supported toolchains (make variable 'TOOLCHAIN')

- GNU Arm&reg; Embedded Compiler v10.3.1 (`GCC_ARM`) - Default value of `TOOLCHAIN`
- Arm&reg; Compiler v6.16 (`ARM`)
- IAR C/C++ Compiler v9.30.1 (`IAR`)

## Supported kits (make variable 'TARGET')

- [PSoC&trade; 4000T CAPSENSE&trade; Evaluation Kit](https://www.infineon.com/CY8CKIT-040T/) (`CY8CKIT-040T`) - Default value of `TARGET`

## Hardware setup

This example uses the board's default configuration. See the [kit user guide](www.infineon.com/002-34472) to ensure that the board is configured correctly to use VDDA at 1.8 V

## Software setup

This example requires no additional software or tools.

## Using the code example

Create the project and open it using one of the following:

<details><summary><b>In Eclipse IDE for ModusToolbox&trade;</b></summary>

1. Click the **New Application** link in the **Quick Panel** (or, use **File** > **New** > **ModusToolbox&trade; Application**). This launches the [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool.

2. Pick a kit supported by the code example from the list shown in the **Project Creator - Choose Board Support Package (BSP)** dialog.

   When you select a supported kit, the example is reconfigured automatically to work with the kit. To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/dgdl/Infineon-ModusToolbox_Library_Manager_2.0_User_Guide-UserManual-v01_00-EN.pdf?fileId=8ac78c8c8386267f0183a960c5945992) to choose the BSP for the supported kit. You can use the Library Manager to select or update the BSP and firmware libraries used in this application. To access the Library Manager, click the link from the **Quick Panel**.

   You can also just start the application creation process again and select a different kit.

   To use the application for a kit not listed here, you may need to update the source files. If the kit does not have the required resources, the application may not work.

3. In the **Project Creator - Select Application** dialog, choose the example by enabling the checkbox.

4. (Optional) Change the suggested **New Application Name**.

5. The **Application(s) Root Path** defaults to the Eclipse workspace which is usually the desired location for the application. If you want to store the application in a different location, you can change the *Application(s) Root Path* value. Applications that share libraries must be in the same root path.

6. Click **Create** to complete the application creation process.

For more details, see the [Eclipse IDE for ModusToolbox&trade; user guide](https://www.infineon.com/MTBEclipseIDEUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mt_ide_user_guide.pdf*).

</details>

<details><summary><b>In command-line interface (CLI)</b></summary>

ModusToolbox&trade; provides the Project Creator as both a GUI tool and the command-line tool (*project-creator-cli*). The CLI tool can be used to create applications from a CLI terminal or from within batch files or shell scripts. This tool is available in the *{ModusToolbox&trade; install directory}/tools_{version}/project-creator/* directory.

Use a CLI terminal to invoke the "project-creator-cli" tool. On Windows, use the command-line "modus-shell" program provided in the ModusToolbox&trade; installation instead of a standard Windows command-line application. This shell provides access to all ModusToolbox&trade; tools. You can access it by typing `modus-shell` in the search box in the Windows menu. In Linux and macOS, you can use any terminal application.

The "project-creator-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--board-id` | Defined in the `<id>` field of the [BSP](https://github.com/Infineon?q=bsp-manifest&type=&language=&sort=) manifest | Required
`--app-id`   | Defined in the `<id>` field of the [CE](https://github.com/Infineon?q=ce-manifest&type=&language=&sort=) manifest | Required
`--target-dir`| Specify the directory in which the application is to be created if you prefer not to use the default current working directory | Optional
`--user-app-name`| Specify the name of the application if you prefer to have a name other than the example's default name | Optional
<br>

The following example clones the "[PSoC&trade; 4: MSCLP CAPSENSE&trade; low-power proximity tuning](https://github.com/Infineon/mtb-example-psoc4-msclp-capsense-lp-proximity)" application with the desired name "CAPSENSE_Low_Power_Proximity_Tuning" configured for the *CY8CKIT-040T* BSP into the specified working directory, *C:/mtb_projects*:

   ```
   project-creator-cli --board-id CY8CKIT-040T --app-id mtb-example-psoc4-msclp-capsense-lp-proximity --user-app-name CAPSENSE_Low_Power_Proximity_Tuning --target-dir "C:/mtb_projects"
   ```

> **Note:** The project-creator-cli tool uses the `git clone` and `make getlibs` commands to fetch the repository and import the required libraries. For details, see the "Project creator tools" section of the [ModusToolbox&trade; user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf*).

To work with a different supported kit later, use the [Library Manager](https://www.infineon.com/ModusToolboxLibraryManager) to choose the BSP for the supported kit. You can invoke the Library Manager GUI tool from the terminal by using the `make library-manager` command or use the Library Manager CLI tool (library-manager-cli) to change the BSP.

The "library-manager-cli" tool has the following arguments:

Argument | Description | Required/optional
---------|-------------|-----------
`--add-bsp-name` | Name of the BSP that should be added to the application | Required
`--set-active-bsp` | Name of the BSP that should be as active BSP for the application | Required
`--add-bsp-version`| Specify the version of the BSP that should be added to the application if you do not wish to use the latest from manifest | Optional
`--add-bsp-location`| Specify the location of the BSP (local/shared) if you prefer to add the BSP in a shared path | Optional

<br>

The following example adds the CY8CKIT-040T BSP to the already created application and makes it the active BSP for the application:

   ```
   library-manager-cli --project "C:/mtb_projects/CAPSENSE_Low_Power_Proximity_Tuning" --add-bsp-name CY8CKIT-040T --add-bsp-version "latest-v4.X" --add-bsp-location "local"

   library-manager-cli --project "C:/mtb_projects/CAPSENSE_Low_Power_Proximity_Tuning" --set-active-bsp APP_CY8CKIT-040T
   ```

</details>

<details><summary><b>In third-party IDEs</b></summary>

Use one of the following options:

- **Use the standalone [Project Creator](https://www.infineon.com/ModusToolboxProjectCreator) tool:**

   1. Launch Project Creator from the Windows Start menu or from *{ModusToolbox&trade; install directory}/tools_{version}/project-creator/project-creator.exe*.

   2. In the initial **Choose Board Support Package** screen, select the BSP, and click **Next**.

   3. In the **Select Application** screen, select the appropriate IDE from the **Target IDE** drop-down menu.

   4. Click **Create** and follow the instructions printed in the bottom pane to import or open the exported project in the respective IDE.

<br>

- **Use command-line interface (CLI):**

   1. Follow the instructions from the **In command-line interface (CLI)** section to create the application, and then import the libraries using the `make getlibs` command.

   2. Export the application to a supported IDE using the `make <ide>` command.

   3. Follow the instructions displayed in the terminal to create or import the application as an IDE project.

For a list of supported IDEs and more details, see the "Exporting to IDEs" section of the [ModusToolbox&trade; user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf*).

</details>

The project already has the necessary settings by default, so you can go to [Operation](#operation) to test the example. To understand the tuning process and follow the stages for this kit or your own board, go to [Tuning procedure](#tuning-procedure) and then test it using [Operation](#operation).

<br>

## Operation

1. Connect the board to your PC using the provided micro USB cable through the KitProg3 USB connector, as shown in  **Figure 1**.

   **Figure 1. Connecting the CY8CKIT-040T kit to a PC**

   <img src="images/psoc4000t_kit_connected.jpg" alt="Figure 1" width="350"/>

2. Program the board using one of the following:

   <details><summary><b>Using Eclipse IDE for ModusToolbox&trade;</b></summary>

      1. Select the application project in the Project Explorer.

      2. In the **Quick Panel**, scroll down, and click **\<Application Name> Program (KitProg3_MiniProg4)**.
   </details>

   <details><summary><b>Using CLI</b></summary>

     From the terminal, execute the `make program` command to build and program the application using the default toolchain to the default target. The target and the toolchain are specified manually.
      ```
      make program TARGET=<BSP> TOOLCHAIN=<toolchain>
      ```

      Example:
      ```
      make program TARGET=CY8CKIT-040T TOOLCHAIN=GCC_ARM
      ```
   </details>
   <br>

3. After programming, the application starts automatically.

   > **Note:** After programming, you see the following error message if debug mode is disabled. This can be ignored or enabling debug solves this error.

   ``` c
   "Error: Error connecting Dp: Cannot read IDR"
   ```

4. To test the application, hover a hand on top of the CAPSENSE&trade; proximity sensor and notice that LED1 turns ON with **GREEN** color and turns OFF when the hand is moved away. In this case, the maximum distance the proximity sensor can sense an object is 35 mm. 

   The sensor can also detect a touch. When the sensor is touched, the LED1 turns ON with the color **BLUE**.

   **Figure 2. LED1 turns GREEN upon hovering the hand on top of the sensor**

   <img src="images/proximity.jpg" alt="Figure 2" width="400"/>

   <br>
5. Spray water over the sensors and observe that LED3 turns ON with RED color indicating system is in **Liquid Active state** due to the presence of water. 

   **Figure 3. Spraying water on top of the sensors**

   <img src="images/psoc_4000t_sensors_water_spray.jpg" alt="Figure 3" width="450"/>

   <br>
6. Use a water dropper (shipped with the kit package) to place water droplets on top of the sensors. Observe that LED3 turns ON with **RED** color, indicating system is in **Liquid Active state** due to the presence of water. 

      **Figure 4. Droplets of water on top of the sensors**

   <img src="images/floating-water-out-of-boundry.png" alt="Figure 4" width="450"/>

   **Table 1. LED Indications for Proximity, Touch and Liquid detection**

    Scenario  | LED  | Color  |
   :------------------| :-----| :-----|
    Hand in Proximity  | LED1 |GREEN  |
    Touch  | LED1 | BLUE |
    Liquid | LED3 | RED |

   <br>

### Monitor data using CAPSENSE&trade; Tuner

1. Open CAPSENSE&trade; Tuner from the 'BSP Configurators' section in the IDE **Quick Panel**.

   You can also run the CAPSENSE&trade; Tuner application standalone from *{ModusToolbox&trade; install directory}/ModusToolbox&trade;/tools_{version}/capsense-configurator/capsense-tuner*. In this case, after opening the application, select **File** > **Open** and open the *design.cycapsense* file of the respective application, which is present in the *{Application root directory}/bsps/TARGET_APP_\<BSP-NAME>/COMPONENT_BSP_DESIGN_MODUS/* folder.

   See the [ModusToolbox&trade; user guide](https://www.infineon.com/ModusToolboxUserGuide) (locally available at *{ModusToolbox&trade; install directory}/docs_{version}/mtb_user_guide.pdf*)for options to open the CAPSENSE&trade; tuner application using the CLI.

2. Ensure that the kit is in CMSIS-DAP Bulk mode (KitProg3 Status LED is ON and not blinking). See [Firmware-loader](https://github.com/Infineon/Firmware-loader) to learn how to update the firmware and switch modes in KitProg3.

3. In the tuner application, click on the **Tuner communication setup** icon or select **Tools** > **Tuner communication setup**. In the window that appears, select the I2C checkbox under KitProg3 and configure it as follows:

   - **I2C address:** 8
   - **Sub-address:** 2 bytes
   - **Speed (kHz):** 400

   These are the same values set in the EZI2C resource.

   **Figure 5. Tuner communication setup parameters**

   <img src="images/tuner-comm-setup.png" alt="Figure 5" width="550"/>

4. Click **Connect** or select **Communication** > **Connect** to establish a connection.

   **Figure 6. Establish connection**

   <img src="images/tuner-connect.png" alt="Figure 6" width="300" />

5. Click **Start** or select **Communication** > **Start** to start data streaming from the device.

   **Figure 7. Start tuner communication**

   <img src="images/tuner-start.png" alt="Figure 7" width="300" />

   The **Widget/Sensor Parameters** tab is updated with the parameters configured in the CAPSENSE&trade; Configurator window. The tuner displays the data from the sensor in the **Widget View** and **Graph View** tabs.

6. Set the **Read mode** to **Synchronized mode**. Navigate to the **Widget view** tab and notice that the **Proximity0** widget is highlighted in blue when you touch it.

   **Figure 8. Widget view of the CAPSENSE&trade; Tuner**

   <img src="images/tuner-widget-view.png" alt="Figure 8" width="750"/>

7. Go to the **Graph View** tab to view the raw count, baseline, difference count, and status for each sensor. Observe that the low-power widget sensor's (**LowPower0_Sns0**) raw count is plotted once the device completes a full-frame scan (or detects a touch) in **WOT** mode and moves to **Active/ALR** mode.

   **Figure 9. Graph view of the CAPSENSE&trade; Tuner**

   <img src="images/tuner-graph-view-intro.png" alt="Figure 9" width="750"/>

8. Observe the **Widget/Sensor parameters** section in the CAPSENSE&trade; Tuner window as shown in Figure 7.

9. Switch to the **SNR Measurement** tab for measuring the SNR and verify that the SNR is above 5:1 and the signal count is above 50; select the **Proximity0** and **Proximity0_Sns0** sensor, and then click **Acquire noise** as follows:

    **Figure 10. CAPSENSE&trade; Tuner - SNR measurement: Acquire noise**

    <img src="images/tuner-acquire-noise.png" alt="Figure 10" width="750"/>

      **Note:** Because the scan refresh rate is lower in **ALR** mode, it will take more time to acquire noise. Touch the CAPSENSE&trade; proximity loop once before clicking **Acquire noise** to transition the device to **ACTIVE** mode to complete the measurement faster.

10. Once noise is acquired, bring your hand near the proximity loop at a distance of around **35 mm** above it and then click **Acquire signal**. Ensure that the hand remains above the proximity loop as long as the signal acquisition is in progress. Observe that the SNR is above 5:1 and the signal count is above 50. If not, repeat signal acquisition by lowering the hand, and thus getting a higher signal.

    The calculated SNR on this proximity widget is displayed, as Figure 9 shows.

    **Figure 11. CAPSENSE&trade; Tuner - SNR measurement: acquire signal**

    <img src="images/tuner-acquire-signal.png" alt="Figure 11" width="750"/>

    The maximum distance the proximity sensor can sense is at the distance where the SNR is greater than 5:1. [Tuning procedure](#tuning-procedure) section explains how changing the configuration affects the distance and SNR.

11. To measure the SNR of the low-power sensor (**LowPower0_Sns0**), set the **Finger threshold** to maximum (65535) in **Widget/Sensor Parameters** for the **LowPower0** widget as shown in Figure 12. And set the Proximity threshold and Proximity Touch Threshold to their maximum (65535) values in the Widget/Sensor Parameters of the Proximity0 widget, as shown in Figure 13.

    This is required to keep the application in Low Power mode. Otherwise, the application will stop scanning the low-power sensor when there is a proximity or touch detected and will transition to active mode. 

      **Figure 12. CAPSENSE&trade; update finger threshold**

      <img src="images/tuner-threshold-update.png" alt="Figure 12"/>
      
      <br>

      **Figure 13. CAPSENSE&trade; update proximity and touch threshold**

      <img src="images/tuner-threshold-update-proximity.png" alt="Figure 13"/>

      <br>

12. Repeat steps 9 and 10 to observe the SNR and signal, as shown in Figure 9.

       **Figure 14. CAPSENSE&trade; Tuner - SNR measurement: low-power widget**

       <img src="images/tuner-lowpower-snr.png" alt="Figure 14" width="750"/>


### Current consumption

Follow the instructions in the **Measure current at different power modes** section of the code example [PSoC™ 4: MSCLP CAPSENSE™ low power](https://github.com/Infineon/mtb-example-psoc4-msclp-capsense-low-power) to measure the current consumption.

# Operation at other voltages

[CY8CKIT-040T kit](https://www.infineon.com/CY8CKIT-040T) supports operating voltages of 1.8 V, 3.3 V, and 5 V. Use voltage selection switch available on top of the kit to set the preferred operating voltage and see the [setup the VDDA supply voltage and Debug mode](#set-up-the-vdda-supply-voltage-and-debug-mode-in-device-configurator) section .

This application functionalities are optimally tuned for 1.8 V. However, you can observe the basic functionalities working across other voltages. It is recommended to tune application at the preferred voltages for optimum performance.

## Tuning procedure


<details><summary><b> Create custom BSP for your board </b></summary>

1. Create a custom BSP for your board having any device, by following the steps given in [ModusToolbox™ BSP Assistant user guide](https://www.infineon.com/dgdl/Infineon-ModusToolbox_BSP_Assistant_1.0_User_Guide-UserManual-v02_00-EN.pdf?fileId=8ac78c8c8386267f0183a972f45c59af). This code example was created for the device "CY8C4046LQI-T452".

2. Open the *design.modus* file from the *{Application root directory}/bsps/TARGET_APP_\<BSP-NAME>/config/* folder obtained in the previous step and enable CAPSENSE&trade; to get the *design.cycapsense* file. CAPSENSE&trade; configuration can then be started from scratch as explained below.


</details>

The following steps explain the tuning procedure for the proximity loop and the low-power widget.

**Note:** See the section "Manual Tuning" in the [AN92239 - Proximity sensing with CAPSENSE&trade;](http://www.cypress.com/documentation/application-notes/an92239-proximity-sensing-capsense) to learn about the considerations for selecting each parameter values. In addition, see the "Low-power widget parameters" section in the [Achieving lowest-power capacitive sensing with PSoC&trade; 4000T](https://www.infineon.com/002-34231) to learn about the considerations for parameter values specific to low-power widgets.

**Figure 15** shows the tuning flow of the proximity widget.

**Figure 15. Proximity widget Tuning flow**

   <img src="images/flowchart-for-tuning.jpg" alt="Figure 15" width="750"/>

To tune the low-power widget, see the **Tuning flow** section of the code example [PSoC™ 4: MSCLP CAPSENSE™ low power](https://github.com/Infineon/mtb-example-psoc4-msclp-capsense-low-power).

Do the following to tune the proximity widget:

- [Stage 1: Set initial hardware parameters](#stage-1-set-initial-hardware-parameters)

- [Stage 2: Measure Sensor Capacitance and set CDAC Dither parameter](#stage-2-measure-sensor-capacitance-and-set-cdac-dither-parameter)

- [Stage 3: Set sense clock frequency](#stage-3-set-sense-clock-frequency)

- [Stage 4: Fine-tune for required SNR, power, and refresh rate](#stage-4-fine-tune-for-required-snr-power-and-refresh-rate)

- [Stage 5: Tune threshold parameters](#stage-5-tune-threshold-parameters)

- [Stage 6: Re-tune threshold parameters for liquid tolerance](#stage-6-re-tune-threshold-parameters-for-liquid-tolerance)

### **Stage 1: Set initial hardware parameters**
-------------------------

1. Connect the board to your PC using the provided USB cable through the KitProg3 USB connector.

2. Launch the Device Configurator tool.

   You can launch the Device Configurator in Eclipse IDE for ModusToolbox&trade; from the **Tools** section in the IDE Quick Panel or in standalone mode from *{ModusToolbox&trade; install directory}/ModusToolbox&trade;/tools_{version}/device-configurator/device-configurator*. In this case, after opening the application, select **File** > **Open** and open the *design.modus* file of the respective application, which is present in the *{Application root directory}/bsps/TARGET_APP_\<BSP-NAME>/COMPONENT_BSP_DESIGN_MODUS* folder.

3. Enable CAPSENSE&trade; channel in Device Configurator as follows:

   **Figure 16. Enable CAPSENSE&trade; in Device Configurator**

   <img src="images/device-configurator.png" alt="Figure 16"/>

   Save the changes and close the window.

4. Launch the CAPSENSE&trade; Configurator tool.

   You can launch the CAPSENSE&trade; Configurator tool in Eclipse IDE for ModusToolbox&trade; from the "CAPSENSE&trade;" peripheral setting in the Device Configurator or directly from the Tools section in the IDE Quick Panel.

   You can also launch it in standalone mode from *{ModusToolbox&trade; install directory}/ModusToolbox&trade;/tools_{version}/capsense-configurator/capsense-configurator*. In this case, after opening the application, select **File** > **Open** and open the *design.cycapsense* file of the respective application, which is present in the *{Application root directory}/bsps/TARGET_APP_\<BSP-NAME>/COMPONENT_BSP_DESIGN_MODUS* folder.

   See the [ModusToolbox&trade; CAPSENSE&trade; Configurator tool guide](https://www.infineon.com/ModusToolboxCapSenseConfig) for step-by-step instructions on how to configure and launch CAPSENSE&trade; in ModusToolbox&trade;.

5. In the **Basic** tab, add a proximity widget 'Proximity0' and a low-power widget 'LowPower0'. Set their sensing mode as CSD RM (self-cap) and the CSD tuning mode as *Manual tuning*.
6. Add a button widget 'CsxGuard', set the sensing mode to 'CSX', and add 4 Rx sensing elements as shown in Figure 17. This widget acts as a water sensor to turn OFF the sensing until water is present on the surface.

   **Figure 17. CAPSENSE&trade; Configurator - Basic tab**

   <img src="images/basic-csd-settings.png" alt="Figure 17"/>


7. Do the following in the **General** tab under the **Advanced** tab:

   1. Select **CAPSENSE&trade; IMO Clock frequency** as **46 MHz**.

   2. Set the **Modulator clock divider** to **2** to obtain the optimum modulator clock frequency. 

   3. Set the **Number of init sub-conversions** based on the hint shown when you hover over the edit box. Retain the default value (which will be set in [Stage 3: Set sense clock frequency](#stage-3-set-sense-clock-frequency)).

   4. Use **Wake-on-Touch settings** to set the refresh rate and frame timeout while in the lowest power mode (Wake-on-Touch mode).

   5. Set **Wake-on-Touch scan interval (ms)** based on the required low-power state scan refresh rate. For example, to get a 16-Hz refresh rate, set the value to **63**.

   6. Set the **Number of frames in Wake-on-Touch** as the maximum number of frames to be scanned in WoT mode if there is no touch detected. This determines the maximum time the device will be kept in the lowest-power mode if there is no user activity. The maximum time can be calculated by multiplying this parameter with the **Wake-on-Touch scan interval (ms)** value.

      For example, to get 10 seconds as the maximum time in WoT mode, set **Number of frames in Wake-on-Touch** to **160** for the scan interval set as 63 ms.

      **Note:** For tuning low-power widgets, **Number of frames in Wake-on-Touch** must be less than the  **Maximum number of raw counts values in SRAM** based on the number of sensors in WoT mode as follows:

      **Table 2. Maximum number of raw counts values in SRAM**

       Number of low <br> power widgets  | Maximum number of <br> raw counts in SRAM  |
      :---------------------| :-----|
       1  | 245 |
       2  | 117 |
       3  | 74 |
       4  | 53 |
       5  | 40 |
       6  | 31 |
       7  | 25 |
       8  | 21 |

   7. Retain the default settings for all regular and low-power widget filters. You can enable or update the filters later, depending on the signal-to-noise ratio (SNR) requirements in [Stage 4: Fine-tune for required SNR, power, and refresh rate](#stage-4-fine-tune-for-required-snr-power-and-refresh-rate).

      Filters are used to reduce the peak-to-peak noise; however, using filters will result in a higher scan time.

      **Figure 18. CAPSENSE&trade; Configurator - General settings**

      <img src="images/advanced-general-settings.png" alt="Figure 18"/>

      **Note:** Each tab has a **Restore Defaults** button to restore the parameters of that tab to their default values.

7. Go to the **CSD settings** tab and make the following changes:

   1. Set **Inactive sensor connection** as **Shield**.

      Connect the inactive sensor, hatch pattern, or any trace that is surrounding the proximity sensor to the driven shield instead of connecting them to ground. This minimizes the signal due to the liquid droplets falling on the sensor. 

   2. Set **Shield mode** as **Active**.

      Setting the shield to active: The driven shield is a signal that replicates the sensor-switching signal. This minimizes the signal due to the liquid droplets falling on the sensor. 

   3. Set **Total shield count** as **6** (Enabling all the inactive sensors as shield during CSD sensor scan).

   4. Select **Enable CDAC auto-calibration** and **Enable compensation CDAC**.

   5. Set **Raw count calibration level (%)** to **70**.

   6. Select **Enable CDAC dither**.

      This helps in removing flat spots by adding white noise that moves the conversion point around the flat-spots region. Refer to the [CAPSENSE&trade; design guide](https://www.infineon.com/AN85951) for more information.

      **Figure 19. CAPSENSE&trade; Configurator - Advanced CSD settings**

      <img src="images/advanced-csd-settings.png" alt="Figure 19"/>

9. Go to the **Widget details** tab.

      Select **Proximity0** from the left pane, and then set the following:

   - **Sense clock divider:** Retain the default value (will be set in [Stage 3:  Set sense clock frequency](#stage-3-set-sense-clock-frequency))

   - **Clock source:** Direct

      **Note:** Spread spectrum clock (SSC) or PRS clock can be used as a clock source to deal with EMI/EMC issues.

   - **Number of sub-conversions: 60**

     60 is a good starting point to ensure a fast scan time and sufficient signal. This value will be adjusted as required in [Stage 4: Fine-tune for required SNR, power, and refresh rate](#stage-4-fine-tune-for-required-snr-power-and-refresh-rate).

   - **Proximity threshold:** 65535

      Proximity threshold is set to the maximum to avoid waking the device up from WoT mode due to touch detection; this is required to find the signal and SNR. This will be adjusted in [Stage 5: Tune threshold parameters](#stage-5-tune-threshold-parameters).
      
   - **Touch threshold:** 65535

      Touch threshold is also set to the maximum to avoid the waking up of the device from WoT.

   - **Noise threshold:** 40

   - **Negative noise threshold:** 40

   - **Low baseline reset:** 65535
      
      Low baseline reset is set to 65535, so that the baseline does not reset at all due to abnormal dips in raw count.

   - **Hysteresis:** 40

   - **ON debounce:** 3

   **Figure 20. CAPSENSE&trade; Configurator - Proximity Widget details tab under the Advanced tab**

   <img src="images/advanced-widget-settings_proximity.png" alt="Figure 20" />

     Now, select **LowPower0** from the left pane, and then set the following:

   - **Sense clock divider:** Retain the default value (will be set in [Stage 3: Set sense clock frequency](#stage-3-set-sense-clock-frequency))

   - **Clock source:** Direct

      **Note:** Spread spectrum clock (SSC) or PRS clock can be used as the clock source to deal with EMI/EMC issues.

   - **Number of sub-conversions: 60**

     60 is a good starting point to ensure a fast scan time and sufficient signal. This value will be adjusted as required in [Stage 4: Fine-tune for required SNR, power, and refresh rate](#stage-4-fine-tune-for-required-snr-power-and-refresh-rate).

   - **Finger threshold:** 65535

      Finger threshold is set to the maximum to avoid the waking the device up from WoT mode due to touch detection so that you can acquire signal for SNR measurement.

   - **Noise threshold:** 10

   - **Negative noise threshold:** 10

   - **Low baseline reset:** 10

   - **ON debounce:** 1

   **Figure 21. CAPSENSE&trade; Configurator - Low-Power Widget details tab under the Advanced tab**

   <img src="images/advanced-widget-settings.png" alt="Figure 21" />

   **Note:** These values reduce the influence of the baseline on the sensor signal, which helps to get the true difference count. Retain the default values for all other threshold parameters; these parameters are set in [Stage 5: Tune threshold parameters](#stage-5-tune-threshold-parameters).

10. Select **CsxGaurd** from the left pane, and then set the following:

   - **Sense clock divider:** Retain the default value (will be set in [Stage 3: Set sense clock frequency](#stage-3-set-sense-clock-frequency))

   - **Clock source:** Direct

      **Note:** Spread spectrum clock (SSC) or PRS clock can be used as a clock source to deal with EMI/EMC issues. Refer to the [CAPSENSE&trade; design guide](https://www.infineon.com/AN85951) for more information.

   - **Number of sub-conversions: 60**

     60 is a good starting point to ensure a fast scan time and sufficient signal. This value will be adjusted as required in [Stage 4: Fine-tune for required SNR, power, and refresh rate](#stage-4-fine-tune-for-required-snr-power-and-refresh-rate).

  - **Finger threshold:** 65535

      Finger threshold is set to the maximum to avoid the waking up of the device from WoT mode due to touch detection so that you can acquire signal for SNR measurement.

   - **Noise threshold:** 10

   - **Negative noise threshold:** 10

   - **Low baseline reset:** 65535

      Since this widget is configured as guard, raw count value lower than baseline will be used to detect liquid presence. 'Low baseline reset' is set to 65535, so that the baseline does not reset at all when there's dip in raw count due to presence of liquid.

   - **Hysteresis:** 40

   - **ON debounce:** 3

      **Figure 22. CAPSENSE&trade; Configurator - CSX Gaurd Widget details tab under the Advanced tab**

      <img src="images/csx-guard-widget-details.png" alt="Figure 22" />


11. Go to the **Scan Configuration** tab to select the pins and scan slots. Do the following:

   1. Configure the pins for electrodes using the drop-down menu.

   2. Configure the scan slots using the **Auto-assign slots** option. The other option is to allot each sensor a scan slot based on the entered slot number.

   3. Select Proximity0_Sns0 as **Ganged** below the **LowPower0** widget as shown in **Figure 24**.

   4. Select CsxGaurd Rx0 electrode and set it as **Ganged** as shown in **Figure 25**. The proximity electrode loop will act as Tx and the electrodes at the edge of the touchpad will act as ganged Rx electrode, as shown in  **Figure 23**.

      **Figure 23. CSX Guard widget electrodes on PCB**

      <img src="images/csx-electrodes.jpg" alt="Figure 23" width= "400"/>

   4. Check the notice list for warning or errors.

   **Figure 24. Scan Configuration tab**

   <img src="images/scan-configuration.png" alt="Figure 24"/>

   **Figure 25. Scan Configuration tab CSX Rx Gangging**

   <img src="images/csx-ganged-rx0.png" alt="Figure 25"/>

12. Click **Save** to apply the settings.

Refer to the [CAPSENSE&trade; design guide](https://www.infineon.com/AN85951) for detailed information on tuning parameters mentioned here.


### **Stage 2: Measure Sensor Capacitance and set CDAC Dither parameter**
------------------
The CAPSENSE&trade; middleware provide Built In Self Test (BIST) API's to measure the capacitances of sensors configured in the application. The sensor capacitances are referred to as  **C<sub>p</sub>** for CSD sensors and **C<sub>m</sub>** for CSX sensor.

The steps to measure the C<sub>p</sub>/C<sub>m</sub> using BIST are as follows.

   1.	Open CAPSENSE&trade; Configurator from **Quick Panel** and enable BIST library.
   
   **Figure 26. Enabling self test library**
   
   <img src="images/bist_measurement.png" alt="Figure 26" width=700>

   <br>

   2.	Get the capacitance(C<sub>p</sub>/C<sub>m</sub>) by following these steps:
        - Add breakpoint at the function call "measure_sensor_capacitance()" function in main.c
        - Run the application in debug mode
        - Click **Step over** button once break point hits
        - Add array variable 'sensor_capacitance' to **Expressions view** tab, which holds the measured Cp values of sensors configured

   **Figure 27. Measure C<sub>p</sub>/C<sub>m</sub> using BIST**

   <img src="images/bist_break_point.png" alt="Figure 27" width=700/>

   <br>
  
   3.	Index of sensor_capacitance array matches with the sensor configuration in CAPSENSE&trade; Configurator as shown in Figure 29.

   **Figure 28. Cp array index alignment**

   <img src="images/cp_alignment.png" alt="Figure 28" width=700/>

   <br>

   4. Refer to [CAPSENSE&trade; library and documents](https://github.com/Infineon/capsense) for more details about BIST.
   5. Keep this feature disabled in CAPSENSE&trade; Configurator, if not used in application.

### **CDAC Dither scale setting**

MSCLP uses CDAC dithering to reduce flat spots. Select the optimal dither scale parameter based on the Sensor capacitance measured in Stage 4 Sensor Capacitance measurement.

See the following table for general recommended values of Dither scale.

   **Table 3. Dither scale recommendation for CSD sensors**
   
   Sensor C<sub>p</sub> Range | CDAC_Dither_scale
   :---: | :---:  
   2pF <= 3pF | 3
   3pF <= 5pF | 2
   5pF <= 3pF | 1
   \>=10pF  | 0

   **Table 4. Dither Scale Recommendation for CSX sensors**
   
   Sensor C<sub>m</sub> Range | CDAC_Dither_scale
   :---: | :---:  
   300fF <= 500fF | 5
   500fF <= 1000fF | 4
   1000fF <= 2000fF | 3
   \>=2pF  | Follow [Table 3](#table-3-dither-scale-recommendation-for-csd-sensors)

 Set the Scale value in CAPSENSE&trade; Configurator as follows.

**Figure 29. CDAC Dither Scale setting**

   <img src="images/dither_scale_setting.png" alt="Figure 29"/>

### Stage 3: Set sense clock frequency
-------------------------
The sense clock is derived from the Modulator clock using a clock-divider and is used to scan the sensor by driving the CAPSENSE&trade; switched capacitor circuits. Both the clock source and clock divider are configurable.

Select the maximum sense clock frequency such that the sensor and shield capacitance are charged and discharged completely in each cycle. This can be verified using an oscilloscope and an active probe. To view the charging and discharging waveforms of the sensor, probe at the sensor (or as close as possible to the sensors), and not at the pins or resistor. 

Refer to **Figure 30** and **Figure 31** for waveforms observed on the shield. **Figure 30**  shows proper charging when the sense clock frequency is correctly tuned. The pulse width is at least 5 Tau  i.e., the voltage is reaching at least 99.3% of the required voltage at the end of each phase. **Figure 31** shows incomplete settling (charging/discharging).


   **Figure 30. Proper charge cycle of a sensor**

   <img src="images/csdrm-waveform.png" alt="" width="700"/>

   **Figure 31. Improper charge cycle of a sensor**

   <img src="images/csdrm-waveform_improper.png" alt="" width="700"/>

   To set the proper sense clock frequency, follow the steps listed below:

   1. Program the board and launch CAPSENSE&trade; Tuner.

   2. Observe the charging waveform of the sensor and shield as described earlier. 

   3. If the charging is incomplete, increase the Sense clock divider. Do this in CAPSENSE&trade; Tuner by selecting the sensor and editing the Sense clock divider parameter in the Widget/Sensor Parameters panel.

      **Note:** 
      - The sense clock divider should be **divisible by 4**. This ensures that all four scan phases have equal durations. 

      - After editing the value, click the **Apply to Device** button and observe the waveform again. Repeat this until complete settling is observed.  

      - Using a passive probe will add an additional parasitic capacitance of around 15 pF; therefore, should be considered during the tuning.

      
   4. Click the **Apply to Project** button so that the configuration is saved to your project. 

      ##### **Figure 32. Sense Clock Divider setting**

      <img src="images/sense-clock-divider-setting.png" alt="Figure 32"/>
      

   5. Repeat this process for all the sensors and the shield. Each sensor may require a different sense clock divider value to charge/discharge completely. But all the sensors which are in the same scan slot need to have the same sense clock source, sense clock divider, and number of sub-conversions. Therefore, take the largest sense clock divider in a given scan slot and apply it to all the other sensors that share that slot.

      **Table 5. Sense clock parameters obtained based on sensors for CY8CKIT-040T**

      Parameter | Value |
      :-------- |:-----------|
      Modulator clock divider | 2 |
      Sense clock divider | 40 |

### Stage 4: Fine-tune for required SNR, power, and refresh rate
-------------------------
The sensor should be tuned to have a minimum SNR of 5:1 and a minimum signal of 50 to ensure reliable operation. The sensitivity can be increased by increasing number of sub-conversions, and noise can be decreased by enabling available filters. 

The steps for optimizing these parameters are as follows:

1. Measure the SNR as mentioned in the [Operation](#operation) section.

   Measure the SNR by placing your hand above the proximity loop at maximum proximity height (35 mm in this case).

2. If the SNR is less than 5:1 increase the number of sub-conversions. Edit the number of sub-conversions (N<sub>sub</sub>) directly in the **Widget/Sensor parameters** tab of the CAPSENSE&trade; Tuner.

      **Note:** Number of sub-conversion should be greater than or equal to 8.

3. PSoC&trade; 4000T CAPSENSE&trade; has a built-in CIC2 filter which increases the resolution for the same scan time. This example has the CIC2 filter enabled.

   Calculate the decimation rate of the CIC2 filter using **Equation 1**. The resolution increases with an increase in the decimation rate; therefore, set the maximum decimation rate indicated by the equation.

      **Equation 1. Recommended Decimation Rate**

      $$DecimationRate = min\left(\frac {SnsClkDiv * N_{sub}}{3},255\right) $$

      Where,
      
      - $N_{sub}$ is Number of Sub-Conversions
      - $SnsClkDiv$ is Sense Clock Divider value

4.  Load the parameters to the device and measure SNR as mentioned in Steps 10 and 11 in the [Operation](#operation) section. 
   
      Repeat steps 1 to 4 until the following conditions are met:

      - Measured SNR from the previous stage is greater than 5:1

      - Signal count is greater than 50

5. If the system is noisy (>40% of signal), enable filters.

   Whenever the CIC2 filter is enabled, it is recommended to enable the IIR filter for optimal noise reduction. Therefore, this example has the IIR filter enabled as well.

   To enable and configure filters available in the system:

   a. Open **CAPSENSE&trade; Configurator** from ModusToolbox&trade; Quick Panel and select the appropriate filter:

      **Figure 33. Filter settings in CAPSENSE&trade; Configurator**

      <img src="images/advanced-filter-settings.png" alt="Figure 33"/>
   
      - Add the filter based on the type of noise in your measurements. See [ModusToolbox&trade; CAPSENSE&trade; configurator guide](https://www.infineon.com/file/492896/download) for details.

   b. Click Save and close CAPSENSE&trade; Configurator. Program the device to update the filter settings.

   >**Note** : Increasing number of sub-conversions and enabling filters increases the scan time which in turn decreases the responsiveness of the sensor. Increase in scan time also increases the power consumption. Therefore, the number of sub-conversions and filter configuration must be optimized to achieve a balance between SNR, power, and refresh rate. 

### Stage 5: Tune threshold parameters
-------------------------
Various thresholds, relative to the signal, need to be set for each sensor. Do the following in CAPSENSE&trade; Tuner to set up the thresholds for a widget:

1. Switch to the **Graph View** tab and select **Proximity0**.

2. Place your hand at 35 mm directly above the proximity sensor and monitor the touch signal in the **Sensor signal** graph, as shown in Figure 34. 

   ##### **Figure 34. Sensor signal when the sensor is touched**

   <img src="images/tuner-threshold-settings.png" alt="Figure 34"/>

3. Note the signal measured and set the thresholds according to the following recommendations:

   - Proximity threshold = 80% of the signal

   - Proximity touch threshold = 80% of the signal

     Here, the touch threshold denotes the threshold for the proximity sensor to detect a touch when it is touched by a finger. When the proximity sensor is touched, the sensor yields a higher signal compared the proximity signal; therefore, it is the **touch signal**. To measure the touch signal count, touch the sensor and monitor the signal in the **Sensor signal** graph.

   - Noise threshold = 40% of the signal

   - Negative noise threshold = 40% of the signal

   - Hysteresis = 10% of signal

   - Low baseline reset = 65535

      Low baseline reset is set to 65535, so that the baseline does not reset at all due to abnormal dip in raw count for long time.

   - Hysteresis = 10% of the signal

   - ON debounce = 3

2. For the **LowPower0** sensor, first configure the Finger threshold to 65535 and wait for the application to enter Low Power mode. Since the Finger threshold is set to maximum, touching the low power button will not switch the application to active mode. Repeat steps 2 to 4 for the low power button.

3. Apply the settings to the device by clicking **To device**.

   **Figure 35. Apply settings to device**

   <img src="images/tuner-apply-settings-device.png" alt="Figure 35"/>

   If your sensor is tuned correctly, you will observe that the proximity status goes from 0 to 1 in the **Status** sub-window of the **Graph View** window as Figure 35 shows. The successful tuning of the proximity sensor is also indicated by LED3 in the kit; it turns ON when the hand comes closer than the maximum distance and turns OFF when the hand is moved away from the proximity sensor.

   **Figure 36. Sensor status in CAPSENSE&trade; Tuner showing proximity status**

   <img src="images/tuner-status.png" alt="Figure 36"/>

   Upon touching the proximity loop, a further change in status from 1 to 3 can be observed, which indicates a touch. Along with this, LED1 will turn ON in blue color.

   **Figure 37. Sensor status in CAPSENSE&trade; Tuner showing touch status**

   <img src="images/tuner-status-touch.png" alt="Figure 37"/>

7. Click **Apply to Project** as Figure 38 shows. The change is updated in the *design.cycapsense* file. 
   
   Close **CAPSENSE&trade; Tuner** and launch **CAPSENSE&trade; Configurator**. You should now see all the changes that you made in the CAPSENSE&trade; Tuner reflected in the **CAPSENSE&trade; Configurator**.

   ##### **Figure 38. Apply settings to Project**

   <img src="images/tuner-apply-settings-project.png" alt="Figure 38"/>

   <br>

   **Table 6. Tuning parameters obtained based on sensors for CY8CKIT-040T**

   Parameter | Proximity0 | LowPower0|
   :-------- |:-----------|:---------
   Proximity signal | 600 |41 |
   Touch signal | 8960 | NA |
   Proximity threshold | 600 |33|
   Touch threshold | 7168 |NA |
   Noise threshold |200|16|
   Negative noise threshold |200 |16 |
   Low baseline reset | 65535 |30 |
   Hysteresis | 40 |NA |
   ON debounce | 3|1|

   **Note:** For the low-power widget the touch threshold is the finger threshold.

   </details>

### Stage 6: Re-tune threshold parameters for liquid tolerance
-------------------------

The **CsxGuard Widget** is configured as a CSX (mutual capacitance sensor) to be triggered when liquid (for example, water) is present at the intersection of the touchpad boundary and proximity sensor loop. When a liquid droplet is present on this sensor setup, mutual capacitance increases, and the raw count detected by CSX drops can be used to deactivate the proximity loop. Once the liquid droplets are removed/wiped off, the raw count again increases and the proximity loop can be re-activated.
Refer to the algorithm implemented in the code example.


2. Tune the Proximity sensor for liquid tolerance:

   1. Sprinkle some water on the surface of the kit such that only a few water droplets are present on the area marked as the Proximity sensor. This is the scenario where target object can still be detected. 
   
   2. Measure the signal of Proximity sensor (Proximity0_Sns0) as per step 11 mentioned in the [Monitor data using CAPSENSE&trade; Tuner](#monitor-data-using-capsense™-tuner) section.

   3. Se the **Proximity threshold** three times that of the signal when water droplets are present on the Proximity sensor. In this case, it is set to 750.


2. To tune the Csx widget for liquid tolerance, follow the below steps:

    1. Sprinkle water on the surface of the kit such that water droplets cover the inside and slightly outside of the entire area marked as the Proximity sensor. This is the scenario where proximity detection will be disabled to prevent false triggers. 

   2. Open the **SNR Measurement** tab and then select **CsxGuard** in the Widget Explorer panel.

   3. Measure the signal of CSX Guard as per step 11 mentioned in the [Monitor data using CAPSENSE&trade; Tuner](#monitor-data-using-capsense™-tuner) section.


   4. Set **Number of sub-conversions:**
      
      Since the CsxGuard sensor widget also uses the CIC2 filter, keep the Number of sub-conversions and decimation rate the same as those of the **Proximity0** widget.

   5. Set **Finger threshold:** 
      
      Since presence of liquid droplets will reduce the raw count below the baseline, positive raw count (above baseline) is not of interest and can be ignored. 

   6. Set **Negative noise threshold:** 
      
      40% of the signal raw count is measured below the baseline when liquid is present on the surface.

   7. Set **Noise threshold:** the same as the **Negative noise threshold**

      Since the presence of liquid droplets will reduce the raw count below the baseline, a positive raw count (above baseline) is not of interest and can be ignored. The value mentioned here is to make sure the baseline is updated in accordance to noise present in the system.

   8. Set **Low baseline reset:**

      Since this widget is configured as guard, raw count value lower than baseline will be used to detect liquid presence. 'Low baseline reset' is set to 65535, so that the baseline does not reset at all when there is a dip in raw count due to the presence of liquid.

   9. Set **Hysteresis**: 10%  of the signal raw count measured below the baseline when liquid is present on the surface

      **Table 7. CSX Guard sensor threshold parameters for liquid tolerance for CY8CKIT-040T**

      Parameter | Raw Count value |
      :-------- |:-----------|
      Number of sub conversions | 255 |
      Touch signal | 10000 |
      Finger threshold | 10000 |
      Noise threshold |200|
      Liquid signal | 300 |
      Negative noise threshold |200 |
      Low baseline reset | 65535 |
      Hysteresis | 30 |
      ON debounce | 3|
      Liquid active threshold | 300 |

      **Note:** Liquid active threshold is mentioned in **main.c** as a user macro **LIQUID_GUARD_NEG_RAWCOUNT_THRESHOLD**

<br>

###  **Process time measurement**
--------------------


In order to set the optimum refresh rate of each power mode, the process time of the application needs to be measured.

Follow these steps to measure the process time of the blocks of application code while excluding the scan time:

1. Enable ENABLE_RUN_TIME_MEASUREMENT macro in main.c as follows:
      
      ```
      #define ENABLE_RUN_TIME_MEASUREMENT (1u)
      ```     
      This macro enables the System tick configuration and runtime measurement functionalities. 

2.	Place the start_runtime_measurement() function call before your application code and the stop_runtime_measurement() function call after it. The stop_runtime_measurement() function will return the execution time in microseconds(µs). 
 
      ```   
         #if ENABLE_RUN_TIME_MEASUREMENT
            uint32_t run_time = 0;
            start_runtime_measurement();
         #endif

         /* User Application Code Start */
         .
         .
         .
         /* User Application Code Stop */

         #if ENABLE_RUN_TIME_MEASUREMENT
            run_time = stop_runtime_measurement();
         #endif
      ```

3.	Run the application in debug mode with breakpoints placed at the active_processing_time and alr_processing_time variables as follows,
      ```
         #if ENABLE_RUN_TIME_MEASUREMENT
            active_processing_time=stop_runtime_measurement();
         #endif
         and 
         #if ENABLE_RUN_TIME_MEASUREMENT
            alr_processing_time=stop_runtime_measurement();
         #endif
      ``` 
4. Read the variables by adding them into **Expressions view** tab.
5. Update related macros with the earlier measured processing times in main.c as follows:
      ```
      #define ACTIVE_MODE_PROCESS_TIME     (xx)

      #define ALR_MODE_PROCESS_TIME        (xx)
      ```
### **Scan time Measurement**
--------------------
Scan time is also required for calculating the refresh rate of the application power modes. The total scan time of all the widgets in this code example is 10 µs.

It can be calculated as follows:

The scan time includes the MSCLP initialization time, Cmod, and the total sub-conversions of the sensor. 

To control the Cmod initialization sequence, set the "Enable Coarse initialization bypass" configurator option as listed in the following table:

Enable coarse initialization bypass | Behaviour
:-------------|:---------
TRUE|Cmod initialization happens only once before scanning the sensors of the widget
FALSE| Cmod initialization happens before scanning each sensor of the widget

Use the following equations to measure the widgets scan time based on coarse initialization bypass options selected: 

**Equation 2. Scan time calculation of a widget with coarse initialization bypass enabled**

$$ScanTime_{widget} = \left(\sum_{sensor=1}^n \left((N_{init} + N_{sub}) * \frac {SnsClkDiv}{F_{mod}}\right)\right) +k $$


**Equation 3. Scan time calculation of a widget with coarse initialization bypass disabled**

$$ScanTime_{widget} = \sum_{sensor=1}^n \left((N_{init} + N_{sub}) * \frac {SnsClkDiv}{F_{mod}} +k \right) $$


where,

- $n$ - Total number of sensors in the widget

- $N_{sub}$ - Number of sub-conversions

- $N_{init}$ - Number of init sub-conversions

- $SnsClkDiv$ - Sense clock divider

- $F_{mod}$ - Modulator clock frequency

- $k$ - Measured Initialization time (MSCLP+Cmod).


This value of '$k$' measured for this application is ~9 µs. It remains constant for all widgets, and can be measured using oscilloscope as shown below;

 **Figure 39. 'k' value measurement**

<img src="images/scantime_wave.png" alt="Figure 39"/>

Update following macros in *main.c* using the scan time calculated. The value remains the same for both macros for this application.

```
#define ACTIVE_MODE_FRAME_SCAN_TIME     (xx)

#define ALR_MODE_FRAME_SCAN_TIME        (xx)
```

**Note :** If the application has more than one widget, add the scan times of individual widgets calculated.

<br>

## Debugging

You can debug the example to step through the code. In the IDE, use the **\<Application Name> Debug (KitProg3_MiniProg4)** configuration in the **Quick Panel**. For details, see the "Program and debug" section in the [Eclipse IDE for ModusToolbox&trade; user guide](https://www.infineon.com/MTBEclipseIDEUserGuide).

By default, the debug option is disabled in the device configurator. To enable the debug option, see the [Setup VDD and Debug mode](#set-up-the-vdda-supply-voltage-and-debug-mode-in-device-configurator) section. To achieve low power consumption, it is recommended to disable it. 

   <br>

## Design and implementation

The project contains the following widgets:

1. Proximity widget with 1 electrode configured in CSD-RM sensing mode

2. Low power widget with 1 electrode configured in CSD-RM sensing mode

3. Mutual-capacitance guard widget with 1 Tx electrode and 4 Rx electrodes configured in CSX sensing mode

See the [Tuning procedure](#tuning-procedure) section for step-by-step instructions on configuring these widgets.
<br>

The project uses the [CAPSENSE&trade; middleware](https://infineon.github.io/capsense/capsense_api_reference_manual/html/index.html); see the [ModusToolbox&trade; software user guide](https://www.infineon.com/ModusToolboxUserGuide) for more details on selecting a middleware.

See [AN85951 – PSoC&trade; 4 and PSoC&trade; 6 MCU CAPSENSE&trade; design guide](https://www.infineon.com/an85951) for more details of CAPSENSE&trade; features and usage.

The design also has an EZI2C peripheral and a SPI master peripheral. The EZI2C slave peripheral is used to monitor the information of sensor raw and processed data on a PC using the CAPSENSE&trade; Tuner available in the Eclipse IDE for ModusToolbox&trade; via I2C communication.

The MOSI pin of the SPI slave peripheral is used to transfer data to the three serially connected LEDs for controlling color, brightness, and ON/OFF operation.

The firmware is designed to support the following application states:

- Active state
- Active low-refresh rate state
- Wake-on-touch state
- Liquid active state

**Figure 40. State machine showing different CAPSENSE&trade; states**

<img src="images/psoc_4000t_simple_state_machine.png" alt="Figure 40" width="400"/>

The firmware state machine and the operation of the device in four different states are explained in the following steps:

1. Initializes and starts all hardware components after reset.

2. The device starts CAPSENSE&trade; operation in the Active state. In this state, the following steps occur:

   1. The device scans all CAPSENSE&trade; sensors present on the board.

   2. During the ongoing scan operation, the CPU moves to the deep sleep state.

   3. The interrupt generated on scan completion wakes the CPU, which processes the sensor data and transfers the data to CAPSENSE&trade; Tuner through EZI2C.

   4. Turns on the serial LED with specific colors and patterns to indicate the specific proximity or touch detection.

   In Active state, a scan of the selected sensors happen with the highest refresh rate of 128 Hz.

3. Enters the Active low-refresh rate state when there is no touch or object in proximity detected for a timeout period. In this state, selected sensors are scanned with a lower refresh rate of 32 Hz. Because of this power consumption in the Active low-refresh rate state is lower compared to the Active state. The state machine returns to the Active state if there is touch or object in proximity detected by the sensor.

4. Enters the Wake-on-touch state when there is no touch or object in proximity detected in Active low-refresh rate state for a timeout period. In this state, the CPU is set to deep sleep, and is not involved in CAPSENSE&trade; operation. This is the lowest power state of the device. In the Wake-on-touch state, the CAPSENSE&trade; hardware executes the scanning of the selected sensors called "low-power widgets" and processes the scan data for these widgets. If touch is detected, the CAPSENSE&trade; block wakes up the CPU and the device enters to the Active state.

5. Enters the 'Liquid Active' state when the guard sensors is activated. Guard sensors are used to detect the presence of liquid on the surface. When the CY8CKIT-040T kit is dipped inside liquid, or liquid is sprayed on the surface, device enters into the 'Liquid Active' state. In this state, no other sensors other than the guard sensor is scanned. This state restricts normal scan operation and avoids any false touch by deactivating the scan operation of active sensors. When the liquid is removed from the surface, system returns to the Active state.

There are three onboard RGB LEDs connected to the SPI MOSI pin of the device. These LEDs form a daisy-chain connection and communicate over the serial interface. See the [LED datasheet](https://media.digikey.com/pdf/Data%20Sheets/Everlight%20PDFs/12-23C_RSGHBHW-5V01_2C_Rev4_12-17-18.pdf) for more details.

### Firmware flow

**Figure 41. Firmware flowchart**

<img src="images/firmware-flowchart.png" alt="Figure 41" width="1100"/>

<br>

### Set up the VDDA supply voltage and debug mode in Device Configurator

1. Open Device Configurator from the Quick Panel.

2. Go to the **System** tab. Select the **Power** resource, and set the VDDA value under **Operating conditions** as follows:

   **Figure 42. Setting the VDDA supply in the System tab of Device Configurator**

   <img src="images/vdda-settings.png" alt="Figure 42"/>

3. By default, the debug mode is disabled for this application to reduce power consumption. Enable the debug mode to enable the SWD pins as follows:

   ##### **Figure 43. Enable debug mode in the System tab of Device Configurator**

   <img src="images/enable_debug.png" alt="Figure 43"/>

<br>

### Resources and settings

**Figure 44. EZI2C settings**

<img src="images/ezi2c-config.png" alt="Figure 44" width="800"/>

**Figure 45 SPI settings**

<img src="images/spi-config.png" alt="Figure 45" width="800"/>

**Table 8. Application resources**

 Resource  |  Alias/object     |    Purpose     |
 :------- | :------------    | :------------ |
 SCB (I2C) (PDL) | CYBSP_EZI2C          | EZI2C slave driver to communicate with CAPSENSE&trade; Tuner |
 SCB (SPI) (PDL) | CYBSP_MASTER_SPI          | SPI master driver to control serial LEDs |
 CAPSENSE&trade; | CYBSP_MSC | CAPSENSE&trade; driver to interact with the MSC hardware and interface the CAPSENSE&trade; sensors |
 Digital pin | CYBSP_SERIAL_LED | To show the proximity operation and power mode states|

</details>

<br>

## Related resources

Resources  | Links
-----------|----------------------------------
Application notes  | [AN79953](https://www.infineon.com/dgdl/Infineon-AN79953_Getting_Started_with_PSoC_4-ApplicationNotes-v21_00-EN.pdf?fileId=8ac78c8c7cdc391c017d07271fd64bc1) – Getting started with PSoC&trade; 4 <br> [AN85951](https://www.infineon.com/AN85951) – PSoC&trade; 4 and PSoC&trade; 6 MCU CAPSENSE&trade; design guide <br> [AN234231](https://www.infineon.com/002-34231) – Achieving lowest-power capacitive sensing with PSoC&trade; 4000T <br> [AN92239](https://www.cypress.com/AN92239) – Proximity Sensing with CAPSENSE&trade;
Code examples  | [Using ModusToolbox&trade;](https://github.com/Infineon/Code-Examples-for-ModusToolbox-Software) on GitHub
Device documentation | [PSoC&trade; 4 datasheets](https://www.infineon.com/cms/en/search.html#!view=downloads&term=psoc4&doc_group=Data%20Sheet) <br>[PSoC&trade; 4 technical reference manuals](https://www.infineon.com/cms/en/search.html#!view=downloads&term=psoc4&doc_group=Additional%20Technical%20Information)
Development kits | Select your kits from the [Evaluation Board finder](https://www.infineon.com/cms/en/design-support/finder-selection-tools/product-finder/evaluation-board).
Libraries on GitHub  | [mtb-pdl-cat2](https://github.com/Infineon/mtb-pdl-cat2) – PSoC&trade; 4 Peripheral Driver Library (PDL) <br>  [mtb-hal-cat2](https://github.com/Infineon/mtb-hal-cat2) – Hardware Abstraction Layer (HAL) library
Middleware on GitHub  | [capsense](https://github.com/Infineon/capsense) – CAPSENSE&trade; library and documents <br> [psoc4-middleware](https://github.com/Infineon/psoc4-middleware) – Links to all PSoC&trade; 4 middleware
Tools | [Eclipse IDE for ModusToolbox&trade;](https://www.infineon.com/modustoolbox) – ModusToolbox&trade; is a collection of easy-to-use software and tools enabling rapid development with Infineon MCUs, covering applications from embedded sense and control to wireless and cloud-connected systems using AIROC&trade; Wi-Fi and Bluetooth&reg; connectivity devices.

<br>

## Other resources

Infineon provides a wealth of data at www.infineon.com to help you select the right device, and quickly and effectively integrate it into your design.


## Document history

Document title: *CE238228* – *PSoC&trade; 4: MSCLP CAPSENSE&trade; liquid tolerant proximity sensing*

 Version | Description of change
 ------- | ---------------------
 1.0.0   | New code example
 1.1.0   | Minor fixes
 1.2.0   | Scan time calculation updates and debug disabled by default

 <br>

---------------------------------------------------------

© Cypress Semiconductor Corporation, 2023. This document is the property of Cypress Semiconductor Corporation, an Infineon Technologies company, and its affiliates ("Cypress").  This document, including any software or firmware included or referenced in this document ("Software"), is owned by Cypress under the intellectual property laws and treaties of the United States and other countries worldwide.  Cypress reserves all rights under such laws and treaties and does not, except as specifically stated in this paragraph, grant any license under its patents, copyrights, trademarks, or other intellectual property rights.  If the Software is not accompanied by a license agreement and you do not otherwise have a written agreement with Cypress governing the use of the Software, then Cypress hereby grants you a personal, non-exclusive, nontransferable license (without the right to sublicense) (1) under its copyright rights in the Software (a) for Software provided in source code form, to modify and reproduce the Software solely for use with Cypress hardware products, only internally within your organization, and (b) to distribute the Software in binary code form externally to end users (either directly or indirectly through resellers and distributors), solely for use on Cypress hardware product units, and (2) under those claims of Cypress’s patents that are infringed by the Software (as provided by Cypress, unmodified) to make, use, distribute, and import the Software solely for use with Cypress hardware products.  Any other use, reproduction, modification, translation, or compilation of the Software is prohibited.
<br>
TO THE EXTENT PERMITTED BY APPLICABLE LAW, CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH REGARD TO THIS DOCUMENT OR ANY SOFTWARE OR ACCOMPANYING HARDWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  No computing device can be absolutely secure.  Therefore, despite security measures implemented in Cypress hardware or software products, Cypress shall have no liability arising out of any security breach, such as unauthorized access to or use of a Cypress product. CYPRESS DOES NOT REPRESENT, WARRANT, OR GUARANTEE THAT CYPRESS PRODUCTS, OR SYSTEMS CREATED USING CYPRESS PRODUCTS, WILL BE FREE FROM CORRUPTION, ATTACK, VIRUSES, INTERFERENCE, HACKING, DATA LOSS OR THEFT, OR OTHER SECURITY INTRUSION (collectively, "Security Breach").  Cypress disclaims any liability relating to any Security Breach, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any Security Breach.  In addition, the products described in these materials may contain design defects or errors known as errata which may cause the product to deviate from published specifications. To the extent permitted by applicable law, Cypress reserves the right to make changes to this document without further notice. Cypress does not assume any liability arising out of the application or use of any product or circuit described in this document. Any information provided in this document, including any sample design information or programming code, is provided only for reference purposes.  It is the responsibility of the user of this document to properly design, program, and test the functionality and safety of any application made of this information and any resulting product.  "High-Risk Device" means any device or system whose failure could cause personal injury, death, or property damage.  Examples of High-Risk Devices are weapons, nuclear installations, surgical implants, and other medical devices.  "Critical Component" means any component of a High-Risk Device whose failure to perform can be reasonably expected to cause, directly or indirectly, the failure of the High-Risk Device, or to affect its safety or effectiveness.  Cypress is not liable, in whole or in part, and you shall and hereby do release Cypress from any claim, damage, or other liability arising from any use of a Cypress product as a Critical Component in a High-Risk Device. You shall indemnify and hold Cypress, including its affiliates, and its directors, officers, employees, agents, distributors, and assigns harmless from and against all claims, costs, damages, and expenses, arising out of any claim, including claims for product liability, personal injury or death, or property damage arising from any use of a Cypress product as a Critical Component in a High-Risk Device. Cypress products are not intended or authorized for use as a Critical Component in any High-Risk Device except to the limited extent that (i) Cypress’s published data sheet for the product explicitly states Cypress has qualified the product for use in a specific High-Risk Device, or (ii) Cypress has given you advance written authorization to use the product as a Critical Component in the specific High-Risk Device and you have signed a separate indemnification agreement.
<br>
Cypress, the Cypress logo, and combinations thereof, WICED, ModusToolbox, PSoC, CapSense, EZ-USB, F-RAM, and Traveo are trademarks or registered trademarks of Cypress or a subsidiary of Cypress in the United States or in other countries. For a more complete list of Cypress trademarks, visit www.infineon.com. Other names and brands may be claimed as property of their respective owners.
