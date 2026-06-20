__int64 __fastcall qcom_icc_bcm_init(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v4; // x0
  int addr; // w0
  __int64 v8; // x2
  unsigned __int64 aux_data; // x0
  int v10; // w8
  _QWORD *v11; // x9
  unsigned int v12; // w8
  unsigned __int64 v13; // x10
  int v14; // w9
  __int64 v15; // x10
  unsigned __int64 v16; // x11
  unsigned int v17; // w20
  _QWORD v19[2]; // [xsp+0h] [xbp-10h] BYREF

  v19[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (*((_BYTE *)a2 + 116) & 1) == 0 && !*((_DWORD *)a2 + 3) )
  {
    v4 = *a2;
    v19[0] = 0;
    addr = cmd_db_read_addr(v4);
    v8 = *a2;
    *((_DWORD *)a2 + 3) = addr;
    if ( addr )
    {
      aux_data = cmd_db_read_aux_data(v8, v19);
      if ( aux_data >= 0xFFFFFFFFFFFFF001LL )
      {
        v17 = aux_data;
        dev_err(a3, "%s command db read error (%ld)\n", (const char *)*a2, aux_data);
        goto LABEL_20;
      }
      if ( v19[0] )
      {
        v10 = *(_DWORD *)aux_data;
        v11 = a2 + 16;
        if ( *(_DWORD *)aux_data <= 1u )
          v10 = 1;
        *((_DWORD *)a2 + 30) = v10;
        v12 = *(unsigned __int16 *)(aux_data + 4);
        if ( v12 <= 1 )
          LOWORD(v12) = 1;
        *((_WORD *)a2 + 62) = v12;
        *((_BYTE *)a2 + 126) = *(_BYTE *)(aux_data + 6);
        *((_BYTE *)a2 + 127) = *(_BYTE *)(aux_data + 7);
        a2[16] = (__int64)v11;
        a2[17] = (__int64)v11;
        a2[18] = (__int64)(a2 + 18);
        a2[19] = (__int64)(a2 + 18);
        if ( a2[12] )
        {
          if ( !a2[21] )
          {
LABEL_17:
            if ( *((_BYTE *)a2 + 113) == 1 )
            {
              *(_QWORD *)(a2[22] + 360) = 0x7FFFFFFF7FFFFFFFLL;
              qcom_icc_bcm_voter_add(*(_QWORD *)(*(_QWORD *)(a1 + 184) + 8LL * *((int *)a2 + 40)));
            }
            goto LABEL_19;
          }
        }
        else
        {
          a2[12] = 1000;
          if ( !a2[21] )
            goto LABEL_17;
        }
        v13 = 0;
        v14 = 1;
        do
        {
          v15 = a2[v13 + 22];
          v16 = *(_QWORD *)(v15 + 392);
          if ( v16 >= 3 )
            __break(0x5512u);
          *(_QWORD *)(v15 + 8 * v16 + 368) = a2;
          ++*(_QWORD *)(v15 + 392);
          v13 = v14++;
        }
        while ( a2[21] > v13 );
        goto LABEL_17;
      }
      dev_err(a3, "%s command db missing or partial aux data\n", *a2);
    }
    else
    {
      dev_err(a3, "%s could not find RPMh address\n", v8);
    }
    v17 = -22;
    goto LABEL_20;
  }
LABEL_19:
  v17 = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return v17;
}
