_QWORD *__fastcall cam_mem_trace_free(_QWORD *result, char a2)
{
  _QWORD *v2; // x19
  char *v3; // x21
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x9
  _QWORD *v8; // x8
  _QWORD *v9; // x10
  __int64 v10; // x11
  _QWORD *v11; // x0

  if ( result )
  {
    v2 = result;
    v3 = (char *)(result - 19);
    if ( *((_DWORD *)result - 38) == 1545761 )
    {
      v5 = *(result - 16);
      if ( *(_DWORD *)((char *)result + v5) != 1545761 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x400000,
          2,
          "cam_mem_trace_free",
          464,
          "Memory overflow likely happened to %s at %pK",
          (const char *)result - 116,
          (char *)result + v5);
      if ( mem_trace_en == 1 && *(v2 - 16) >= (unsigned __int64)(unsigned int)mass_mem_threshold )
        ((void (__fastcall *)(char *))cam_mem_trace_record_mass_mem)(v3);
      v6 = raw_spin_lock_irqsave(&dword_2FDB40);
      v7 = v6;
      if ( (__int64 *)g_trace != &g_trace )
      {
        v8 = (_QWORD *)*(v2 - 17);
        v9 = v2 - 18;
        if ( (_QWORD *)*v8 == v2 - 18 && (v10 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
        {
          *(_QWORD *)(v10 + 8) = v8;
          *v8 = v10;
        }
        else
        {
          _list_del_entry_valid_or_report(v2 - 18);
        }
        *(v2 - 18) = v9;
        *(v2 - 17) = v9;
        qword_2FDB48 = qword_2FDB48 - *(v2 - 16) - 156;
        raw_spin_unlock_irqrestore(&dword_2FDB40, v7);
        v11 = v3;
        if ( (a2 & 1) == 0 )
          return (_QWORD *)kvfree(v11);
        return (_QWORD *)kfree(v11);
      }
      raw_spin_unlock_irqrestore(&dword_2FDB40, v6);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        0x400000,
        2,
        "cam_mem_trace_free",
        472,
        "Empty memory trace list. Fallback to kvfree.");
      if ( (a2 & 1) == 0 )
      {
LABEL_18:
        v11 = v2;
        return (_QWORD *)kvfree(v11);
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x400000,
        2,
        "cam_mem_trace_free",
        450,
        "Likely memory corruption - No header magic detected for %pK",
        result);
      if ( (a2 & 1) == 0 )
        goto LABEL_18;
    }
    v11 = v2;
    return (_QWORD *)kfree(v11);
  }
  return result;
}
