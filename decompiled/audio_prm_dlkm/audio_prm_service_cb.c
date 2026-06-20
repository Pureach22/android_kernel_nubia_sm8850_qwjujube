__int64 __fastcall audio_prm_service_cb(__int64 a1, __int64 a2)
{
  char v3; // w8

  printk(&unk_6EF7, "audio_prm_service_cb");
  if ( a2 == 1 )
  {
    mutex_lock(&unk_6D28);
    v3 = 1;
    goto LABEL_5;
  }
  if ( !a2 )
  {
    mutex_lock(&unk_6D28);
    v3 = 0;
    is_apm_ready_check_done = 0;
LABEL_5:
    byte_6D68 = v3;
    mutex_unlock(&unk_6D28);
  }
  return 1;
}
