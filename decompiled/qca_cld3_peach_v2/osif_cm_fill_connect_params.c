__int64 __fastcall osif_cm_fill_connect_params(__int64 result, unsigned int *a2)
{
  __int64 v2; // x19
  char *v4; // x20
  int v5; // t1
  int v6; // w9

  _ReadStatusReg(SP_EL0);
  if ( a2 )
  {
    v2 = result;
    result = *a2;
    if ( (_DWORD)result )
    {
      result = _qdf_mem_malloc(result, "osif_cm_fill_connect_params", 479);
      *(_QWORD *)(v2 + 176) = result;
      if ( result )
      {
        result = qdf_mem_copy(result, *((_QWORD *)a2 + 1), *a2);
        *(_DWORD *)(v2 + 168) = *a2;
      }
    }
    *(_DWORD *)(v2 + 188) = a2[5];
    *(_BYTE *)(v2 + 184) = *(_BYTE *)(v2 + 184) & 0xFE | *((_BYTE *)a2 + 16);
    *(_BYTE *)(v2 + 192) = *((_BYTE *)a2 + 24);
    v5 = *(unsigned int *)((char *)a2 + 25);
    v4 = (char *)a2 + 25;
    if ( v5 | *((unsigned __int16 *)v4 + 2) )
    {
      v6 = *(_DWORD *)v4;
      *(_WORD *)(v2 + 18) = *((_WORD *)v4 + 2);
      *(_DWORD *)(v2 + 14) = v6;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
