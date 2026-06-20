char *__fastcall lim_add_self_he_cap(char *result, __int64 a2)
{
  char *v2; // x19

  if ( a2 )
  {
    v2 = result;
    result[152] = 1;
    qdf_mem_copy(result + 156, (const void *)(a2 + 8680), 0x3Cu);
    return (char *)qdf_mem_copy(v2 + 216, (const void *)(a2 + 8740), 0x12u);
  }
  return result;
}
