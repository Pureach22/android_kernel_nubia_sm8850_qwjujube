__int64 __fastcall venus_hfi_scale_buses(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned int v7; // w0
  __int64 v8; // x4
  unsigned int v9; // w20
  __int64 v10; // x8
  __int64 (__fastcall *v11)(__int64, __int64, __int64); // x8

  v3 = *(_QWORD *)(a1 + 320);
  core_lock(v3);
  v7 = _resume(v3);
  if ( v7 )
  {
    v9 = v7;
    if ( a1 && (msm_vidc_debug & 1) != 0 )
      printk(&unk_87BBE, "err ", a1 + 340, "venus_hfi_scale_buses", v8);
  }
  else if ( v3
         && (v10 = *(_QWORD *)(v3 + 6552)) != 0
         && (v11 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(v10 + 96)) != nullptr )
  {
    if ( *((_DWORD *)v11 - 1) != -219393110 )
      __break(0x8228u);
    v9 = v11(v3, a2, a3);
  }
  else
  {
    v9 = 0;
  }
  core_unlock(v3);
  return v9;
}
