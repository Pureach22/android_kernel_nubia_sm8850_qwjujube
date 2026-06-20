__int64 __fastcall kgsl_memdesc_print_vbo_ranges(__int64 result, __int64 a2)
{
  __int64 v2; // x19
  __int64 i; // x0
  __int64 v5; // x22

  if ( (*(_BYTE *)(result + 84) & 4) != 0 )
  {
    v2 = result;
    result = mutex_trylock(result + 144);
    if ( (_DWORD)result )
    {
      for ( i = interval_tree_iter_first(v2 + 128, 0, -1); i; i = interval_tree_iter_next(v5, 0, -1) )
      {
        v5 = i;
        seq_printf(
          a2,
          "%5d %5d 0x%16.16lx-0x%16.16lx\n",
          *(_DWORD *)(v2 + 248),
          *(_DWORD *)(*(_QWORD *)(i - 8) + 248LL),
          *(_QWORD *)(i + 24),
          *(_QWORD *)(i + 32));
      }
      return mutex_unlock(v2 + 144);
    }
  }
  return result;
}
