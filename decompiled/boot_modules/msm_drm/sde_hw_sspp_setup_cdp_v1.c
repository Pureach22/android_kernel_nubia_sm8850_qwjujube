__int64 __fastcall sde_hw_sspp_setup_cdp_v1(__int64 result, unsigned __int8 *a2, unsigned int a3)
{
  __int64 v5; // x19
  int v6; // w8
  int v7; // w8
  unsigned int v8; // w9
  unsigned int v9; // w2
  int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    if ( a2 )
    {
      v5 = result;
      v10 = 0;
      result = sspp_subblk_offset(result, 1, &v10);
      if ( !(_DWORD)result )
      {
        if ( a3 >= 2 )
          v6 = 12288;
        else
          v6 = 4096;
        v7 = v10 + v6;
        v10 = v7;
        if ( a3 >= 3 )
        {
          result = printk(&unk_27E748, "sde_hw_sspp_setup_cdp_v1");
        }
        else
        {
          v8 = *a2;
          if ( a2[1] )
            v8 |= 2u;
          if ( a2[2] )
            v8 |= 4u;
          if ( *((_DWORD *)a2 + 1) == 1 )
            v9 = v8 | 8;
          else
            v9 = v8;
          result = sde_reg_write(v5, v7 + 120, v9, "cdp_cntl_offset");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
