unsigned __int64 __fastcall sde_encoder_misr_setup(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 *v3; // x22
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned int v9; // w8
  unsigned int v10; // w8
  void *v11; // x0
  size_t v12; // x21
  int v13; // w9
  int v15; // [xsp+Ch] [xbp-114h] BYREF
  int v16; // [xsp+10h] [xbp-110h] BYREF
  char s[257]; // [xsp+17h] [xbp-109h] BYREF
  __int64 v18; // [xsp+118h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_26;
  v3 = *(__int64 **)(a1 + 32);
  if ( !v3 )
    goto LABEL_26;
  memset(s, 0, sizeof(s));
  v6 = *v3;
  v15 = 0;
  v16 = 0;
  if ( !v6 )
  {
    v11 = &unk_26FCAB;
    goto LABEL_25;
  }
  v7 = *(_QWORD *)(v6 + 56);
  if ( !v7 || (v8 = *(_QWORD *)(v7 + 8)) == 0 )
  {
    v11 = &unk_234896;
LABEL_25:
    printk(v11, "sde_encoder_get_kms");
    goto LABEL_26;
  }
  if ( !*(_QWORD *)(v8 + 152) )
    goto LABEL_18;
  mutex_lock(v8 + 3696);
  if ( (*(_QWORD *)(*(_QWORD *)(v8 + 152) + 22008LL) & 0x400000000LL) == 0
    || *(_DWORD *)(v8 + 3664) != 1
    || (v9 = *(_DWORD *)(v8 + 3656), v9 > 6)
    || ((1 << v9) & 0x64) == 0 )
  {
    v10 = *(_DWORD *)(v8 + 3656);
    if ( v10 > 4 || ((1 << v10) & 0x1A) == 0 )
    {
      mutex_unlock(v8 + 3696);
LABEL_18:
      if ( a3 >= 0x100 )
        v12 = 256;
      else
        v12 = a3;
      _check_object_size(s, v12, 0);
      if ( !inline_copy_from_user_3((int)s, a2, v12) )
      {
        s[v12] = 0;
        if ( sscanf(s, "%u %u", &v15, &v16) == 2 )
        {
          v13 = v16;
          *((_DWORD *)v3 + 200) = v15;
          *((_BYTE *)v3 + 808) = 1;
          *((_DWORD *)v3 + 203) = v13;
          goto LABEL_27;
        }
      }
LABEL_26:
      a3 = -22;
      goto LABEL_27;
    }
  }
  mutex_unlock(v8 + 3696);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "enc%d misr enable/disable not allowed\n", *((_DWORD *)v3 + 6));
  a3 = -524;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return a3;
}
