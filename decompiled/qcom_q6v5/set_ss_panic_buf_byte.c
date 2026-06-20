__int64 __fastcall set_ss_panic_buf_byte(__int64 result)
{
  ss_atomic_panic_intval = (unsigned __int8)result;
  return result;
}
