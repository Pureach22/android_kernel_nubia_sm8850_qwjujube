unsigned __int64 __fastcall sde_crtc_misr_setup(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 *v3; // x22
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x23
  size_t v9; // x21
  unsigned int v10; // w8
  unsigned int v11; // w8
  void *v12; // x0
  void *v13; // x0
  int v14; // w9
  int v16; // [xsp+Ch] [xbp-114h] BYREF
  int v17; // [xsp+10h] [xbp-110h] BYREF
  char s[257]; // [xsp+17h] [xbp-109h] BYREF
  __int64 v19; // [xsp+118h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_27;
  v3 = *(__int64 **)(a1 + 32);
  if ( !v3 )
    goto LABEL_27;
  memset(s, 0, sizeof(s));
  v6 = *v3;
  v16 = 0;
  v17 = 0;
  if ( !v6 || (v7 = *(_QWORD *)(v6 + 56)) == 0 )
  {
    v12 = &unk_25E167;
LABEL_22:
    printk(v12, "_sde_crtc_get_kms");
    v13 = &unk_25E374;
LABEL_26:
    printk(v13, "_sde_crtc_misr_setup");
    goto LABEL_27;
  }
  v8 = *(_QWORD *)(v7 + 8);
  if ( !v8 )
  {
    v12 = &unk_234896;
    goto LABEL_22;
  }
  if ( a3 >= 0x100 )
    v9 = 256;
  else
    v9 = a3;
  _check_object_size(s, v9, 0);
  if ( inline_copy_from_user_2((__int64)s, a2, v9) )
  {
    v13 = &unk_256CE2;
    goto LABEL_26;
  }
  s[v9] = 0;
  if ( sscanf(s, "%u %u", &v16, &v17) != 2 )
  {
LABEL_27:
    a3 = -22;
    goto LABEL_28;
  }
  if ( *(_QWORD *)(v8 + 152) )
  {
    mutex_lock(v8 + 3696);
    if ( (*(_QWORD *)(*(_QWORD *)(v8 + 152) + 22008LL) & 0x400000000LL) != 0
      && *(_DWORD *)(v8 + 3664) == 1
      && (v10 = *(_DWORD *)(v8 + 3656), v10 <= 6)
      && ((1 << v10) & 0x64) != 0
      || (v11 = *(_DWORD *)(v8 + 3656), v11 <= 4) && ((1 << v11) & 0x1A) != 0 )
    {
      mutex_unlock(v8 + 3696);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "crtc:%d misr enable/disable not allowed\n", *((_DWORD *)v3 + 28));
      goto LABEL_27;
    }
    mutex_unlock(v8 + 3696);
  }
  *((_BYTE *)v3 + 7357) = v16 != 0;
  v14 = v17;
  *((_BYTE *)v3 + 7358) = 1;
  *((_DWORD *)v3 + 1840) = v14;
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return a3;
}
