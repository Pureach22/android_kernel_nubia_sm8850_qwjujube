unsigned __int16 *__fastcall synx_global_get_parents_locked(
        unsigned __int16 *result,
        _DWORD *a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  if ( result && a2 )
  {
    *a2 = result[8];
    a2[1] = result[9];
    a2[2] = result[10];
    a2[3] = result[11];
  }
  else if ( (synx_debug & 1) != 0 )
  {
    return (unsigned __int16 *)printk(&unk_261D7, &unk_29207, "synx_global_get_parents_locked", 591, a5, a6);
  }
  return result;
}
