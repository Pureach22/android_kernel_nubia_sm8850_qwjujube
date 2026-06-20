__int64 __fastcall osif_cm_unlink_bss(__int64 result, int *a2)
{
  __int64 v4; // x20
  __int16 v5; // w8
  int v6; // w9
  __int64 v7; // x19

  _ReadStatusReg(SP_EL0);
  if ( *a2 | *((unsigned __int16 *)a2 + 2) )
  {
    if ( *a2 != -1 || *((__int16 *)a2 + 2) != -1 )
    {
      v4 = result;
      result = _qdf_mem_malloc(720, "osif_cm_unlink_bss", 271);
      if ( result )
      {
        *(_BYTE *)(result + 16) = 1;
        v5 = *((_WORD *)a2 + 2);
        v6 = *a2;
        v7 = result;
        *(_WORD *)(result + 74) = v5;
        *(_DWORD *)(result + 70) = v6;
        ucfg_scan_flush_results(*(_QWORD *)(v4 + 152), result);
        result = _qdf_mem_free(v7);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
