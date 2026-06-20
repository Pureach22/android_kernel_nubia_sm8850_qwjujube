__int64 __fastcall wmi_discard_fw_event(__int64 a1)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a1 + 8);
  if ( !v2 )
    return 4;
  if ( *(_QWORD *)(v2 + 8) )
  {
    _qdf_nbuf_free(*(_QWORD *)(v2 + 8));
    v2 = *(_QWORD *)(a1 + 8);
  }
  _qdf_mem_free(v2);
  *(_QWORD *)(a1 + 8) = 0;
  *(_DWORD *)(a1 + 4) = 0;
  *(_WORD *)a1 = 0;
  return 0;
}
