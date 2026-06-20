__int64 __fastcall update_dump_size(__int64 a1, __int64 a2, _QWORD *a3, _QWORD *a4)
{
  __int64 result; // x0
  void *v9; // x0

  if ( !*a4 )
  {
    result = ((__int64 (__fastcall *)(_QWORD, __int64))md_register_memory_dump)((unsigned int)((_DWORD)a2 << 20), a1);
    if ( (result & 1) == 0 )
      return result;
    *a4 = a2 << 20;
    result = __ratelimit(&update_dump_size__rs, "update_dump_size");
    if ( !(_DWORD)result )
      return result;
    v9 = &unk_113ECF;
    return printk(v9, a1);
  }
  if ( (md_unregister_memory_dump(a1) & 1) == 0 )
  {
    result = __ratelimit(&update_dump_size__rs_125, "update_dump_size");
    if ( !(_DWORD)result )
      return result;
    v9 = &unk_113A3E;
    return printk(v9, a1);
  }
  *a3 = 0;
  if ( !a2 )
  {
    *a4 = 0;
    result = __ratelimit(&update_dump_size__rs_117, "update_dump_size");
    if ( !(_DWORD)result )
      return result;
    v9 = &unk_112A1C;
    return printk(v9, a1);
  }
  if ( (((__int64 (__fastcall *)(_QWORD, __int64))md_register_memory_dump)((unsigned int)((_DWORD)a2 << 20), a1) & 1) != 0 )
  {
    *a4 = a2 << 20;
    result = __ratelimit(&update_dump_size__rs_119, "update_dump_size");
    if ( !(_DWORD)result )
      return result;
    v9 = &unk_112F26;
    return printk(v9, a1);
  }
  if ( (((__int64 (__fastcall *)(_QWORD, __int64))md_register_memory_dump)(*(unsigned int *)a4, a1) & 1) != 0 )
  {
    result = __ratelimit(&update_dump_size__rs_121, "update_dump_size");
    if ( (_DWORD)result )
      return printk(&unk_113EF1, a1);
  }
  else
  {
    result = __ratelimit(&update_dump_size__rs_123, "update_dump_size");
    if ( (_DWORD)result )
      result = printk(&unk_11367D, a1);
    *a4 = 0;
  }
  return result;
}
