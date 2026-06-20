__int64 __fastcall msm_asoc_machine_remove(__int64 a1)
{
  __int64 v1; // x19
  __int64 v3; // x8
  __int64 v4; // x0

  v1 = *(_QWORD *)(a1 + 168);
  if ( v1 && (v3 = *(_QWORD *)(v1 + 784)) != 0 )
    v4 = *(_QWORD *)(v3 + 8);
  else
    v4 = 0;
  ((void (__fastcall *)(__int64))msm_common_snd_deinit)(v4);
  snd_event_master_deregister(a1 + 16);
  return snd_soc_unregister_card(v1);
}
