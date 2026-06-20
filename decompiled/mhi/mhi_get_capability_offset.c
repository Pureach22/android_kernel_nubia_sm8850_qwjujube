__int64 __fastcall mhi_get_capability_offset(__int64 a1, int a2, _DWORD *a3)
{
  __int64 v6; // x1
  __int64 result; // x0
  __int64 v8; // x2
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 32);
  v9[0] = 0;
  result = mhi_read_reg_field(a1, v6, 36, 0xFFFFFFFFLL, a3);
  if ( !(_DWORD)result )
  {
    v8 = (unsigned int)*a3;
    while ( 1 )
    {
      if ( (unsigned int)v8 > 0xFFF )
      {
LABEL_9:
        result = 4294967290LL;
        goto LABEL_2;
      }
      result = mhi_read_reg_field(a1, *(_QWORD *)(a1 + 32), v8, 4278190080LL, (_DWORD *)v9 + 1);
      if ( (_DWORD)result )
        goto LABEL_2;
      if ( HIDWORD(v9[0]) == a2 )
        break;
      result = mhi_read_reg_field(a1, *(_QWORD *)(a1 + 32), (unsigned int)*a3, 16773120, v9);
      if ( (_DWORD)result )
        goto LABEL_2;
      v8 = LODWORD(v9[0]);
      *a3 = v9[0];
      if ( !(_DWORD)v8 )
        goto LABEL_9;
    }
    result = 0;
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
