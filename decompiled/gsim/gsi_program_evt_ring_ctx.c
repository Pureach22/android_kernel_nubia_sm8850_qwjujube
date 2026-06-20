__int64 __fastcall gsi_program_evt_ring_ctx(int *a1, unsigned __int8 a2, unsigned int a3)
{
  int v6; // w8
  int v7; // w9
  int v8; // w8
  int v9; // w8
  __int64 v10; // x2
  char *v11; // x3
  __int64 v12; // x0
  __int64 result; // x0
  int v14; // [xsp+4h] [xbp-4Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-48h] BYREF
  int v16; // [xsp+10h] [xbp-40h] BYREF
  int v17; // [xsp+14h] [xbp-3Ch] BYREF
  _DWORD v18[3]; // [xsp+18h] [xbp-38h] BYREF
  int v19; // [xsp+24h] [xbp-2Ch] BYREF
  int v20; // [xsp+28h] [xbp-28h] BYREF
  int v21; // [xsp+2Ch] [xbp-24h] BYREF
  int v22; // [xsp+30h] [xbp-20h] BYREF
  __int64 v23; // [xsp+34h] [xbp-1Ch]
  __int64 v24; // [xsp+3Ch] [xbp-14h]
  int v25; // [xsp+44h] [xbp-Ch]
  __int64 v26; // [xsp+48h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v7 = a1[1];
  v24 = 0;
  v23 = 0;
  v25 = v6;
  v8 = a1[2];
  v18[0] = 0;
  v16 = 0;
  v15 = 0;
  HIDWORD(v23) = v7;
  v22 = v8;
  gsihal_write_reg_nk_fields(12, a3, a2, &v22);
  v21 = a1[3];
  gsihal_write_reg_nk_fields(37, a3, a2, &v21);
  v20 = *((_QWORD *)a1 + 2);
  gsihal_write_reg_nk_fields(38, a3, a2, &v20);
  v19 = a1[5];
  gsihal_write_reg_nk_fields(39, a3, a2, &v19);
  v9 = *((unsigned __int16 *)a1 + 16);
  v18[1] = *((unsigned __int8 *)a1 + 34);
  v18[2] = v9;
  gsihal_write_reg_nk_fields(40, a3, a2, v18);
  v17 = a1[9];
  gsihal_write_reg_nk_fields(41, a3, a2, &v17);
  if ( *a1 == 15 )
  {
    v16 = *((_QWORD *)a1 + 9);
    gsihal_write_reg_nk_fields(42, a3, a2, &v16);
    v10 = a2;
    v11 = (char *)&v15 + 4;
    v12 = 43;
    HIDWORD(v15) = a1[19];
  }
  else
  {
    v16 = *((_QWORD *)a1 + 6);
    gsihal_write_reg_nk_fields(42, a3, a2, &v16);
    HIDWORD(v15) = a1[13];
    gsihal_write_reg_nk_fields(43, a3, a2, (char *)&v15 + 4);
    LODWORD(v15) = *((_QWORD *)a1 + 9);
    gsihal_write_reg_nk_fields(44, a3, a2, &v15);
    v10 = a2;
    v11 = (char *)&v14;
    v12 = 45;
    v14 = a1[19];
  }
  result = gsihal_write_reg_nk_fields(v12, a3, v10, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}
