__int64 __fastcall _qdf_minidump_log(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x29
  __int64 v4; // x30
  __int64 v7; // x22
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x19
  unsigned int inserted; // w20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // [xsp+8h] [xbp-28h]

  if ( qdf_va_md_initialized == 1 )
  {
    v27 = v4;
    v7 = result;
    v8 = _qdf_mem_malloc(0x48u, "__qdf_minidump_log", 4502);
    if ( v8 )
    {
      v17 = v8;
      sized_strscpy(v8 + 24, a3, 32);
      *(_QWORD *)(v17 + 16) = v7;
      *(_DWORD *)(v17 + 56) = a2;
      qword_76D270 = raw_spin_lock_irqsave(&qdf_va_md_list_lock);
      inserted = qdf_list_insert_front(&qdf_va_md_list, (_QWORD *)v17);
      result = raw_spin_unlock_irqrestore(&qdf_va_md_list_lock, qword_76D270);
      if ( inserted )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: Failed to insert qdf va md entry, status %d",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "__qdf_minidump_log",
          inserted,
          v3,
          v27);
        return _qdf_mem_free(v17);
      }
    }
    else
    {
      return qdf_trace_msg(
               0x38u,
               2u,
               "%s: malloc failed for %s: %pK, %zu",
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               "__qdf_minidump_log",
               a3,
               v7,
               a2,
               v3,
               v27);
    }
  }
  return result;
}
