__int64 __fastcall audio_prm_probe(__int64 a1)
{
  __int64 result; // x0
  unsigned int v3; // w19
  void *v4; // x0

  if ( (audio_notifier_probe_status() & 1) == 0 )
  {
    printk(&unk_7016, "audio_prm_probe");
    return 4294966779LL;
  }
  of_property_read_variable_u32_array(*(_QWORD *)(a1 + 744), "qcom,sleep-api-supported", &dword_6D6C, 1, 0);
  result = audio_notifier_register("audio_prm", 0, &service_nb);
  if ( (result & 0x80000000) == 0 )
  {
    *(_QWORD *)(a1 + 152) = &g_prm;
    g_prm = a1;
    v3 = result;
    _init_waitqueue_head(&unk_6D10, "&g_prm.wait", &audio_prm_probe___key);
    v4 = &unk_7146;
    byte_6D68 = 1;
LABEL_8:
    printk(v4, "audio_prm_probe");
    return v3;
  }
  if ( (_DWORD)result != -517 )
  {
    v3 = result;
    v4 = &unk_6F4E;
    goto LABEL_8;
  }
  return result;
}
