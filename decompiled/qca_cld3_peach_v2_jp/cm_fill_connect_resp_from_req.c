__int64 __fastcall cm_fill_connect_resp_from_req(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int16 v4; // w10
  int *v5; // x8
  int v6; // w8
  int *v7; // x9
  __int16 v8; // w10
  int v9; // w9
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a2 + 864);
  if ( v2 )
  {
    v3 = *(_QWORD *)(v2 + 24);
    v4 = *(_WORD *)(v3 + 5);
    LODWORD(v3) = *(_DWORD *)(v3 + 1);
    *(_WORD *)(result + 12) = v4;
    *(_DWORD *)(result + 8) = v3;
    v5 = (int *)(*(_QWORD *)(v2 + 24) + 1064LL);
LABEL_3:
    v6 = *v5;
    goto LABEL_8;
  }
  if ( *(_DWORD *)(a2 + 40) | *(unsigned __int16 *)(a2 + 44) )
    v7 = (int *)(a2 + 40);
  else
    v7 = (int *)(a2 + 85);
  v8 = *((_WORD *)v7 + 2);
  v9 = *v7;
  *(_WORD *)(result + 12) = v8;
  *(_DWORD *)(result + 8) = v9;
  v6 = *(_DWORD *)(a2 + 92);
  if ( !v6 )
  {
    v5 = (int *)(a2 + 96);
    goto LABEL_3;
  }
LABEL_8:
  *(_DWORD *)(result + 48) = v6;
  *(_QWORD *)(result + 14) = *(_QWORD *)(a2 + 52);
  v10 = *(_QWORD *)(a2 + 76);
  v11 = *(_QWORD *)(a2 + 60);
  v12 = *(_QWORD *)(a2 + 68);
  *(_BYTE *)(result + 46) = *(_BYTE *)(a2 + 84);
  *(_QWORD *)(result + 38) = v10;
  LOBYTE(v10) = *(_BYTE *)(result + 1);
  *(_QWORD *)(result + 30) = v12;
  *(_QWORD *)(result + 22) = v11;
  LOBYTE(v10) = v10 & 0xFE | ((*(_BYTE *)(a2 + 216) & 2) != 0);
  *(_BYTE *)(result + 1) = v10;
  *(_BYTE *)(result + 1) = (*(_BYTE *)(a2 + 216) >> 1) & 2 | v10 & 0xFD;
  *(_BYTE *)(result + 152) = *(_BYTE *)(a2 + 240);
  _ReadStatusReg(SP_EL0);
  return result;
}
