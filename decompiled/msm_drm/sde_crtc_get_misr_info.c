__int64 __fastcall sde_crtc_get_misr_info(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v6; // w8
  unsigned int v7; // w8
  void *v8; // x0
  void *v9; // x0

  if ( !a2 )
  {
    v9 = &unk_21D3FC;
    return printk(v9, "sde_crtc_get_misr_info");
  }
  *(_BYTE *)a2 = 0;
  *(_DWORD *)(a2 + 4) = 0;
  if ( !result )
  {
    v9 = &unk_25E167;
    return printk(v9, "sde_crtc_get_misr_info");
  }
  if ( !*(_QWORD *)result || (v2 = *(_QWORD *)(*(_QWORD *)result + 56LL)) == 0 )
  {
    v8 = &unk_25E167;
LABEL_20:
    printk(v8, "_sde_crtc_get_kms");
    v9 = &unk_25E374;
    return printk(v9, "sde_crtc_get_misr_info");
  }
  v3 = *(_QWORD *)(v2 + 8);
  if ( !v3 )
  {
    v8 = &unk_234896;
    goto LABEL_20;
  }
  if ( *(_QWORD *)(v3 + 152) )
  {
    v4 = result;
    v5 = a2;
    mutex_lock(v3 + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(v3 + 152) + 22008LL) & 0x400000000LL) != 0 && *(_DWORD *)(v3 + 3664) == 1 )
    {
      v6 = *(_DWORD *)(v3 + 3656);
      if ( v6 <= 6 && ((1 << v6) & 0x64) != 0 )
        return mutex_unlock(v3 + 3696);
    }
    v7 = *(_DWORD *)(v3 + 3656);
    if ( v7 <= 4 && ((1 << v7) & 0x1A) != 0 )
      return mutex_unlock(v3 + 3696);
    mutex_unlock(v3 + 3696);
    a2 = v5;
    result = v4;
  }
  *(_BYTE *)a2 = *(_BYTE *)(result + 7357);
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(result + 7360);
  return result;
}
