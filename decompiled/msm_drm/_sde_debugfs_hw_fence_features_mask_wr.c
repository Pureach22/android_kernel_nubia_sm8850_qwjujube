__int64 __fastcall sde_debugfs_hw_fence_features_mask_wr(__int64 a1, unsigned __int64 a2, size_t a3)
{
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v8; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x20
  void *v12; // x0
  unsigned __int64 v15; // x10
  unsigned __int64 v22; // x10
  __int64 v23; // [xsp+0h] [xbp-30h] BYREF
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v25; // [xsp+10h] [xbp-20h]
  _WORD v26[7]; // [xsp+18h] [xbp-18h] BYREF
  __int64 v27; // [xsp+28h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    result = -22;
    if ( a3 <= 0x1D && *(_QWORD *)(a1 + 32) )
    {
      v7 = a1;
      v23 = 0;
      *(_QWORD *)s = 0;
      v25 = 0;
      memset(v26, 0, sizeof(v26));
      _check_object_size(s, a3, 0);
      if ( inline_copy_from_user_2((__int64)s, a2, a3) )
      {
        v12 = &unk_256CE2;
      }
      else
      {
        if ( a3 > 0x1D )
        {
          __break(1u);
          goto LABEL_17;
        }
        v11 = *(_QWORD *)(v7 + 32);
        s[a3] = 0;
        if ( sscanf(s, "%u %u", (char *)&v23 + 4, &v23) == 2 )
        {
          v9 = (unsigned __int64)HIDWORD(v23) >> 6;
          v8 = 1LL << SBYTE4(v23);
          v10 = v11 + 7928;
          if ( !(_DWORD)v23 )
          {
            _X9 = (unsigned __int64 *)(v10 + 8 * v9);
            __asm { PRFM            #0x11, [X9] }
            do
              v22 = __ldxr(_X9);
            while ( __stxr(v22 & ~v8, _X9) );
            goto LABEL_11;
          }
LABEL_17:
          _X9 = (unsigned __int64 *)(v10 + 8 * v9);
          __asm { PRFM            #0x11, [X9] }
          do
            v15 = __ldxr(_X9);
          while ( __stxr(v15 | v8, _X9) );
LABEL_11:
          result = a3;
          goto LABEL_12;
        }
        v12 = &unk_279F6C;
      }
      printk(v12, "_sde_debugfs_hw_fence_features_mask_wr");
      result = -22;
    }
  }
  else
  {
    result = -22;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
