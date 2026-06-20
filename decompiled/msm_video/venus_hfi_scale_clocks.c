__int64 __fastcall venus_hfi_scale_clocks(__int64 a1, unsigned int a2)
{
  __int64 v2; // x19
  unsigned int v5; // w0
  __int64 v6; // x4
  unsigned int v7; // w20
  __int64 v8; // x8
  _DWORD *v9; // x8

  v2 = *(_QWORD *)(a1 + 320);
  core_lock(v2);
  v5 = _resume(v2);
  if ( v5 )
  {
    v7 = v5;
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_87BBE, "err ", a1 + 340, "venus_hfi_scale_clocks", v6);
  }
  else if ( v2 && (v8 = *(_QWORD *)(v2 + 6552)) != 0 && (v9 = *(_DWORD **)(v8 + 104)) != nullptr )
  {
    if ( *(v9 - 1) != -1742341011 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64, _QWORD))v9)(v2, a2);
  }
  else
  {
    v7 = 0;
  }
  core_unlock(v2);
  return v7;
}
