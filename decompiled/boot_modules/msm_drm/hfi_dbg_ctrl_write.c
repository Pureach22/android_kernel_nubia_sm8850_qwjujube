size_t __fastcall hfi_dbg_ctrl_write(__int64 a1, int a2, unsigned __int64 a3)
{
  size_t v3; // x19
  int v6; // [xsp+Ch] [xbp-24h] BYREF
  _QWORD v7[4]; // [xsp+10h] [xbp-20h] BYREF

  v7[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = 0;
  memset(v7, 0, 24);
  if ( a1 )
  {
    v3 = a3;
    if ( a3 > 0x17 || (_check_object_size(v7, a3, 0), inline_copy_from_user_1((int)v7, a2, v3)) )
    {
      v3 = -14;
    }
    else
    {
      *((_BYTE *)v7 + v3) = 0;
      if ( (unsigned int)kstrtouint(v7, 0, &v6) )
      {
        printk(&unk_261D6C, "hfi_dbg_ctrl_write");
        v3 = -14;
      }
      else
      {
        *(_DWORD *)(hfi_dbg + 328) = v6;
      }
    }
  }
  else
  {
    printk(&unk_24F9FD, "hfi_dbg_ctrl_write");
    v3 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v3;
}
