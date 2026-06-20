__int64 __fastcall slim_readb(__int64 a1, unsigned __int16 a2)
{
  char v2; // w8
  _QWORD *v3; // x0
  __int64 result; // x0
  unsigned __int8 v5; // [xsp+Ch] [xbp-44h] BYREF
  _QWORD v6[4]; // [xsp+10h] [xbp-40h] BYREF
  unsigned __int8 v7; // [xsp+30h] [xbp-20h] BYREF
  __int16 v8; // [xsp+31h] [xbp-1Fh]
  char v9; // [xsp+33h] [xbp-1Dh]
  __int16 v10; // [xsp+34h] [xbp-1Ch]
  char v11; // [xsp+36h] [xbp-1Ah]
  char v12; // [xsp+37h] [xbp-19h]
  _QWORD *v13; // [xsp+38h] [xbp-18h]
  __int64 v14; // [xsp+40h] [xbp-10h]
  __int64 v15; // [xsp+48h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 0x10000;
  v6[1] = &v5;
  v8 = 24576;
  v2 = *(_BYTE *)(a1 + 932);
  v3 = *(_QWORD **)(a1 + 920);
  LOWORD(v6[0]) = a2;
  v12 = v2;
  v6[2] = 0;
  v6[3] = 0;
  v9 = 0;
  v11 = 0;
  v13 = v6;
  v14 = 0;
  if ( !v3 )
    goto LABEL_7;
  v5 = 0;
  if ( a2 >= 0xC00u )
  {
    dev_err(*v3, "Sanity check failed:msg:offset:0x%x, mc:%d\n", a2, 96);
LABEL_7:
    result = 4294967274LL;
    goto LABEL_8;
  }
  v7 = 7;
  v10 = (16 * a2) | 8;
  LODWORD(result) = slim_do_transfer(v3, &v7);
  if ( (int)result >= 0 )
    result = v5;
  else
    result = (unsigned int)result;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
