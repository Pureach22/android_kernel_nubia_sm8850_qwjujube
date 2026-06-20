__int64 __fastcall dp_parser_get(__int64 a1)
{
  __int64 result; // x0

  result = devm_kmalloc(a1 + 16, 872, 3520);
  if ( !result )
    return -12;
  *(_QWORD *)result = a1;
  *(_QWORD *)(result + 840) = dp_parser_parse;
  *(_QWORD *)(result + 848) = dp_parser_get_io;
  *(_QWORD *)(result + 856) = dp_parser_get_io_buf;
  *(_QWORD *)(result + 864) = dp_parser_clear_io_buf;
  return result;
}
