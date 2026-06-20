char *__fastcall lim_add_self_eht_cap(char *result, __int64 a2)
{
  char *v2; // x19

  if ( a2 )
  {
    v2 = result;
    result[256] = 1;
    qdf_mem_copy(result + 260, (const void *)(a2 + 10072), 0x5Cu);
    return (char *)qdf_mem_copy(v2 + 352, (const void *)(a2 + 10164), 0xCu);
  }
  return result;
}
