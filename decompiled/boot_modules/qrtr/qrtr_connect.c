__int64 __fastcall qrtr_connect(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v3; // x20
  __int64 v6; // x9
  unsigned int v7; // w0
  __int64 v8; // x9
  unsigned int v9; // w19
  __int64 result; // x0
  _DWORD v11[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0xC && *(_WORD *)a2 == 42 )
  {
    v3 = *(_QWORD *)(a1 + 24);
    lock_sock_nested(v3, 0);
    *(_BYTE *)(v3 + 18) = 7;
    v6 = *(_QWORD *)(a1 + 24);
    *(_DWORD *)a1 = 1;
    if ( (*(_QWORD *)(v6 + 96) & 0x100) == 0
      || (v11[2] = 0, v11[0] = 42, v11[1] = qrtr_local_nid, (v7 = _qrtr_bind(a1, v11, 1)) == 0) )
    {
      v8 = *a2;
      v7 = 0;
      *(_DWORD *)(v3 + 860) = *((_DWORD *)a2 + 2);
      *(_QWORD *)(v3 + 852) = v8;
      *(_DWORD *)a1 = 3;
      *(_BYTE *)(v3 + 18) = 1;
    }
    v9 = v7;
    release_sock(v3);
    result = v9;
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
