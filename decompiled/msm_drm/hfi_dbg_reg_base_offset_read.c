__int64 __fastcall hfi_dbg_reg_base_offset_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  _QWORD *v4; // x23
  __int64 result; // x0
  signed int v9; // w0
  unsigned __int64 v10; // x20
  _QWORD v11[4]; // [xsp+0h] [xbp-20h] BYREF

  v11[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v11, 0, 24);
  if ( !hfi_dbg )
  {
    printk(&unk_26C2D0, "hfi_dbg_reg_base_offset_read");
    result = -22;
    goto LABEL_11;
  }
  if ( !a1 )
  {
    result = -22;
    goto LABEL_11;
  }
  v4 = *(_QWORD **)(a1 + 32);
  if ( !v4 )
  {
    result = -19;
    goto LABEL_11;
  }
  if ( !*a4 )
  {
    mutex_lock(hfi_dbg + 272);
    if ( (*v4 & 3LL) == 0 )
    {
      v9 = scnprintf(v11, 24, "0x%08zx %zx\n", *v4, v4[1]);
      if ( (unsigned int)v9 >= 0x18 )
      {
        mutex_unlock(hfi_dbg + 272);
        goto LABEL_5;
      }
      if ( a3 >= 0x18 )
      {
        v10 = v9;
        _check_object_size(v11, v9, 1);
        if ( !inline_copy_to_user_0(a2, (__int64)v11, v10) )
        {
          *a4 += v10;
          mutex_unlock(hfi_dbg + 272);
          result = v10;
          goto LABEL_11;
        }
      }
    }
    mutex_unlock(hfi_dbg + 272);
    result = -14;
    goto LABEL_11;
  }
LABEL_5:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
