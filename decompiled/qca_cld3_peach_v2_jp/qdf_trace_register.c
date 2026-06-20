__int64 __fastcall qdf_trace_register(__int64 result, __int64 a2)
{
  if ( (unsigned int)result >= 0xA7 )
  {
    __break(0x5512u);
    return qdf_trace_dump_all();
  }
  else
  {
    qdf_trace_cb_table[(unsigned int)result] = a2;
  }
  return result;
}
