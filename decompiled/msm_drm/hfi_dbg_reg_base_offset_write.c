__int64 __fastcall hfi_dbg_reg_base_offset_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  _QWORD *v3; // x22
  __int64 result; // x0
  __int64 v7; // x9
  __int64 v8; // [xsp+8h] [xbp-28h] BYREF
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v10; // [xsp+18h] [xbp-18h]
  __int64 v11; // [xsp+20h] [xbp-10h]
  __int64 v12; // [xsp+28h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  *(_QWORD *)s = 0;
  v10 = 0;
  v11 = 0;
  if ( !hfi_dbg )
  {
    printk(&unk_26C2D0, "hfi_dbg_reg_base_offset_write");
    result = -22;
    goto LABEL_12;
  }
  if ( !a1 )
    goto LABEL_8;
  v3 = *(_QWORD **)(a1 + 32);
  if ( !v3 )
  {
    result = -19;
    goto LABEL_12;
  }
  if ( a3 > 0x17
    || (_check_object_size(s, a3, 0), inline_copy_from_user_1((__int64)s, a2, a3))
    || (s[a3] = 0, sscanf(s, "%8x %x", (char *)&v8 + 4, &v8) != 2) )
  {
    result = -14;
    goto LABEL_12;
  }
  if ( (v8 & 0x300000000LL) == 0 && (_DWORD)v8 )
  {
    if ( (unsigned int)v8 >= 0x41 )
    {
      printk(&unk_25E292, "hfi_dbg_reg_base_offset_write");
      LODWORD(v8) = 64;
    }
    mutex_lock(hfi_dbg + 272);
    v7 = (unsigned int)v8;
    *v3 = HIDWORD(v8);
    v3[1] = v7;
    mutex_unlock(hfi_dbg + 272);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "offset=%x cnt=%x\n", HIDWORD(v8), v8);
    result = a3;
  }
  else
  {
LABEL_8:
    result = -22;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
