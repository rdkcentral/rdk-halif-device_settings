# Device Settings Module

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Device Settings Sub modules details](#device-settings-sub-modules-details)

## Acronyms, Terms and Abbreviations

- `HAL` \- Hardware Abstraction Layer
- `DS` \- Device Settings

## Description

This document provides the links for the specific sub-modules of the Device Settings.

## Device Settings Sub modules details

|SNo|Sub-module Name|`HAL` Specification|Header File(s)|Settings Template File |
|---|--------------|-----------|-----------------|---------------------|
|1|`DS` Host|[`DS` Host `HAL` Specification](./docs/pages/ds-audio_halSpec.md)|[dsHost.h](./include/dsHost.h)|N/A|
|2|`DS` Front Panel Display|[`DS` Front Panel Display `HAL` Specification](./docs/pages/ds-front-panel-display_halSpec.md)|[dsFPD.h](./include/dsFPD.h), [dsFPDTypes.h](./include/dsFPDTypes.h) |[frontPanelSettings_template.hpp](./docs/pages/frontPanelSettings_template.hpp)|
|3|`DS` Display|[`DS` Display `HAL` Specification](./docs/pages/ds-display_halSpec.md)|[dsDisplay.h](./include/dsDisplay.h), [dsAVDTypes.h](./include/dsAVDTypes.h) |N/A|
|4|`DS` HDMI Input|[`DS` HDMI Input `HAL` Specification](./docs/pages/ds-hdmi-in_halSpec.md)|[dsHdmiIn.h](./include/dsHdmiIn.h), [dsHdmiInTypes.h](./include/dsHdmiInTypes.h) |N/A|
|5|`DS` Composite Input|[`DS` Composite Input `HAL` Specification](./docs/pages/ds-composite-in_halSpec.md)|[dsCompositeIn.h](./include/dsCompositeIn.h), [dsCompositeInTypes.h](./include/dsCompositeInTypes.h) |N/A|
|6|`DS` Audio|[`DS` Audio `HAL` Specification](./docs/pages/ds-audio_halSpec.md)|[dsAudio.h](./include/dsAudio.h), [dsAVDTypes.h](./include/dsAVDTypes.h) |[dsAudioSettings_template.h](docs/pages/dsAudioSettings_template.h)|
|7|`DS` Video Device|[`DS` Video Device `HAL` Specification](./docs/pages/ds-video-device_halSpec.md)|[dsVideoDevice.h](./include/dsVideoDevice.h), [dsVideoDeviceTypes.h](./include/dsVideoDeviceTypes.h)|[dsVideoDeviceSettings_template.h](docs/pages/dsVideoDeviceSettings_template.h)
|8|`DS` Video Port|[`DS` Video Port `HAL` Specification](./docs/pages/ds-video-port_halSpec.md)|[dsVideoPort.h](./include/dsVideoPort.h), [dsAVDTypes.h](./include/dsAVDTypes.h)|[dsVideoPortSettings_template.h](docs/pages/dsVideoPortSettings_template.h), [dsVideoResolutionSettings_template.h](docs/pages/dsVideoResolutionSettings_template.h)