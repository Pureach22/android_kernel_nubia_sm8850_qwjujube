__int64 __fastcall sde_dbg_reg_base_offset_write(__int64 a1, unsigned __int64 a2, size_t a3)
{
  _QWORD *v3; // x19
  unsigned __int64 v6; // x8
  __int64 result; // x0
  bool v8; // cf
  unsigned __int64 v9; // x8
  int v10; // w2
  __int64 v11; // x9
  unsigned int v12; // [xsp+8h] [xbp-28h] BYREF
  unsigned int v13; // [xsp+Ch] [xbp-24h] BYREF
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v15; // [xsp+18h] [xbp-18h]
  __int64 v16; // [xsp+20h] [xbp-10h]
  __int64 v17; // [xsp+28h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 92;
  v13 = 0;
  if ( !a1 )
    goto LABEL_15;
  v3 = *(_QWORD **)(a1 + 32);
  if ( !v3 )
  {
    result = -19;
    goto LABEL_18;
  }
  if ( a3 > 0x17
    || (v15 = 0, v16 = 0, *(_QWORD *)s = 0, _check_object_size(s, a3, 0), inline_copy_from_user_5((__int64)s, a2, a3))
    || (s[a3] = 0, sscanf(s, "%6x %x", &v13, &v12) != 2) )
  {
    result = -14;
    goto LABEL_18;
  }
  v6 = v3[18];
  result = -22;
  v8 = v6 >= v13;
  v9 = v6 - v13;
  if ( v8 && (v13 & 3) == 0 )
  {
    v10 = v12;
    if ( v9 < v12 )
    {
      v10 = v9;
      v12 = v9;
    }
    if ( v10 )
    {
      if ( (_QWORD *)v3[2] == v3 + 2 || (sde_dbg_reg_base_is_valid_range(v3) & 1) != 0 )
      {
        mutex_lock(&unk_2942D0);
        v11 = v12;
        v3[16] = v13;
        v3[17] = v11;
        mutex_unlock(&unk_2942D0);
        result = a3;
        goto LABEL_18;
      }
LABEL_15:
      result = -22;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
