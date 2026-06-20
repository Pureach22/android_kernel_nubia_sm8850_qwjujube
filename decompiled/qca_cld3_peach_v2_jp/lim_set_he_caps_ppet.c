__int64 __fastcall lim_set_he_caps_ppet(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x9
  __int64 v4; // x8
  unsigned int v6; // w20
  __int64 v7; // x8
  char v8; // w21
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  char v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v3 = 1433;
  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 == 1 )
    v3 = 1408;
  v6 = 25;
  v14 = v4;
  v7 = *(_QWORD *)(a1 + 8);
  v8 = *(_BYTE *)(a2 + 1);
  v13 = 0;
  v11 = 0;
  v12 = 0;
  v10 = 0;
  qdf_mem_copy(&v10, (const void *)(v7 + v3), 0x19u);
  if ( !v13 )
  {
    if ( HIBYTE(v12) )
    {
      v6 = 24;
    }
    else if ( BYTE6(v12) )
    {
      v6 = 23;
    }
    else if ( BYTE5(v12) )
    {
      v6 = 22;
    }
    else if ( BYTE4(v12) )
    {
      v6 = 21;
    }
    else if ( BYTE3(v12) )
    {
      v6 = 20;
    }
    else if ( BYTE2(v12) )
    {
      v6 = 19;
    }
    else if ( BYTE1(v12) )
    {
      v6 = 18;
    }
    else if ( (_BYTE)v12 )
    {
      v6 = 17;
    }
    else if ( HIBYTE(v11) )
    {
      v6 = 16;
    }
    else if ( BYTE6(v11) )
    {
      v6 = 15;
    }
    else if ( BYTE5(v11) )
    {
      v6 = 14;
    }
    else if ( BYTE4(v11) )
    {
      v6 = 13;
    }
    else if ( BYTE3(v11) )
    {
      v6 = 12;
    }
    else if ( BYTE2(v11) )
    {
      v6 = 11;
    }
    else if ( BYTE1(v11) )
    {
      v6 = 10;
    }
    else if ( (_BYTE)v11 )
    {
      v6 = 9;
    }
    else if ( HIBYTE(v10) )
    {
      v6 = 8;
    }
    else if ( BYTE6(v10) )
    {
      v6 = 7;
    }
    else if ( BYTE5(v10) )
    {
      v6 = 6;
    }
    else if ( BYTE4(v10) )
    {
      v6 = 5;
    }
    else if ( BYTE3(v10) )
    {
      v6 = 4;
    }
    else if ( BYTE2(v10) )
    {
      v6 = 3;
    }
    else if ( BYTE1(v10) )
    {
      v6 = 2;
    }
    else
    {
      v6 = (_BYTE)v10 != 0;
    }
  }
  qdf_mem_copy((void *)(a2 + (unsigned __int8)(v8 + 3)), &v10, v6);
  _ReadStatusReg(SP_EL0);
  return v6;
}
