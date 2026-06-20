__int64 __fastcall qcom_glink_spss_unregister(__int64 result)
{
  _QWORD *v1; // x19
  __int64 v2; // x8
  __int64 v3; // x8

  if ( result )
  {
    v1 = (_QWORD *)result;
    disable_irq(*(unsigned int *)(result + 912));
    qcom_glink_native_remove(v1[119]);
    mbox_free_channel(v1[127]);
    v2 = v1[128];
    **(_DWORD **)(v2 + 56) = 0;
    **(_DWORD **)(v2 + 48) = 0;
    v3 = v1[129];
    **(_DWORD **)(v3 + 56) = 0;
    **(_DWORD **)(v3 + 48) = 0;
    return device_unregister(v1);
  }
  return result;
}
