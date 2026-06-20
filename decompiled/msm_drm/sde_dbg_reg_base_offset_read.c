__int64 __fastcall sde_dbg_reg_base_offset_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x22
  __int64 result; // x0
  __int64 v9; // x3
  __int64 v10; // x19
  int v11; // w0
  unsigned __int64 v12; // x20
  unsigned __int64 v13; // x0
  _QWORD v14[4]; // [xsp+0h] [xbp-20h] BYREF

  v14[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v14, 0, 24);
  if ( !a1 )
    goto LABEL_6;
  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    result = -19;
    goto LABEL_11;
  }
  if ( !a4 )
  {
LABEL_6:
    result = -22;
    goto LABEL_11;
  }
  if ( !*a4 )
  {
    mutex_lock(&unk_2942D0);
    v9 = *(_QWORD *)(v4 + 128);
    if ( (v9 & 3) == 0 )
    {
      v11 = snprintf((char *)v14, 0x18u, "0x%08zx %zx\n", v9, *(_QWORD *)(v4 + 136));
      if ( (unsigned int)v11 > 0x17 )
      {
        v10 = 0;
        goto LABEL_10;
      }
      if ( a3 >= 0x18 )
      {
        v12 = v11;
        _check_object_size(v14, v11, 1);
        v13 = a2;
        v10 = v12;
        if ( !inline_copy_to_user_3(v13, (__int64)v14, v12) )
        {
          *a4 += v12;
          goto LABEL_10;
        }
      }
    }
    v10 = -14;
LABEL_10:
    mutex_unlock(&unk_2942D0);
    result = v10;
    goto LABEL_11;
  }
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
