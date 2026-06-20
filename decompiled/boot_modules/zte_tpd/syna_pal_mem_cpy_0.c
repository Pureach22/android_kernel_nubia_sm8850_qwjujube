_QWORD *__fastcall syna_pal_mem_cpy_0(_QWORD *result, unsigned int a2, _QWORD *a3)
{
  __int64 v3; // x8

  if ( result && a3 )
  {
    if ( a2 <= 0xF )
    {
      return (_QWORD *)printk(&unk_3944E, "syna_pal_mem_cpy", 16);
    }
    else
    {
      v3 = a3[1];
      *result = *a3;
      result[1] = v3;
    }
  }
  return result;
}
