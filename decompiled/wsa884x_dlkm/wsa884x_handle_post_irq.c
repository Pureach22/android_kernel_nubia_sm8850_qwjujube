__int64 __fastcall wsa884x_handle_post_irq(__int64 result)
{
  _QWORD *v1; // x19
  _QWORD v2[2]; // [xsp+0h] [xbp-10h] BYREF

  v2[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  if ( result )
  {
    v1 = (_QWORD *)result;
    if ( *(_DWORD *)(result + 208) )
    {
LABEL_3:
      result = 1;
      goto LABEL_11;
    }
    if ( (*(_QWORD *)(result + 680) & 1) != 0 )
      regmap_update_bits_base(*(_QWORD *)result, 13360, 1, 1, 0, 0, 0);
    usleep_range_state(1000, 1100, 2);
    regmap_read(*v1, 13699, (char *)v2 + 4);
    regmap_read(*v1, 13700, v2);
    result = 1;
    *(_BYTE *)(v1[2] + 1008LL) = v2[0] != 0;
    if ( *(_BYTE *)(v1[2] + 1008LL) == 1 )
    {
      regmap_update_bits_base(*v1, 13360, 1, 0, 0, 0, 0);
      *((_DWORD *)v1 + 52) = 1;
      usleep_range_state(1000, 1100, 2);
      *((_DWORD *)v1 + 52) = 0;
      if ( (v1[85] & 1) != 0 )
        regmap_update_bits_base(*v1, 13360, 1, 1, 0, 0, 0);
      usleep_range_state(1000, 1100, 2);
      regmap_read(*v1, 13699, (char *)v2 + 4);
      regmap_read(*v1, 13700, v2);
      result = 1;
      *(_BYTE *)(v1[2] + 1008LL) = v2[0] != 0;
      if ( *(_BYTE *)(v1[2] + 1008LL) == 1 )
      {
        regmap_update_bits_base(*v1, 13360, 1, 0, 0, 0, 0);
        *((_DWORD *)v1 + 52) = 1;
        usleep_range_state(1000, 1100, 2);
        goto LABEL_3;
      }
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
