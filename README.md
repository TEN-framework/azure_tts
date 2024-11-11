# azure_tts

TEN extension of [azure Text to speech service](https://learn.microsoft.com/en-us/azure/ai-services/speech-service/overview#text-to-speech), which converts input text into human like synthesized speech.      

## Features

- Text to speech
- [Rich languages and voices support](https://learn.microsoft.com/en-us/azure/ai-services/speech-service/language-support?tabs=tts)
- [Optimized for Low latency](https://learn.microsoft.com/en-us/azure/ai-services/speech-service/how-to-lower-speech-synthesis-latency?pivots=programming-language-csharp)
- Interruptible     

## API

| property | type | default | description | 
| - | - | - | - | 
| `azure_subscription_key` | `string` | `""` | Azure Speech service subscription key | 
| `azure_subscription_region` | `string` | `""` | Azure Speech service subscription region | 
| `azure_synthesis_voice_name` | `string` | `""` | e.g., `en-US-AdamMultilingualNeural`, check more available voices in [languages and voices support](https://learn.microsoft.com/en-us/azure/ai-services/speech-service/language-support?tabs=tts) | 

## Development

### Build

Only `linux/amd64` building inside container is supported at the moment.      

```bash
# inside docker ghcr.io/ten-framework/ten_agent_build:0.2.2

tman install
tgn gen linux x64 debug -- is_clang=false && tgn build linux x64 debug
tgn gen linux x64 release -- is_clang=false && tgn build linux x64 release
```     

Refer to [ci](.github/workflows/ci.yml) for more details.      


### Unit test

<!-- how to do unit test for the extension -->

## Misc

<!-- others if applicable -->
