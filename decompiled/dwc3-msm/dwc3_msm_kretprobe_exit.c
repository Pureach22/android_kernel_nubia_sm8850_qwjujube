__int64 dwc3_msm_kretprobe_exit()
{
  unregister_kretprobe(&dwc3_msm_probes);
  unregister_kretprobe(&unk_5B8);
  unregister_kretprobe(&unk_660);
  unregister_kretprobe(&unk_708);
  unregister_kretprobe(&unk_7B0);
  unregister_kretprobe(&unk_858);
  unregister_kretprobe(&unk_900);
  unregister_kretprobe(&unk_9A8);
  unregister_kretprobe(&unk_A50);
  unregister_kretprobe(&unk_AF8);
  unregister_kretprobe(&unk_BA0);
  unregister_kretprobe(&unk_C48);
  return unregister_kretprobe(&unk_CF0);
}
