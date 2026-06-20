__int64 __fastcall sg_remove_scat(unsigned __int16 *a1)
{
  __int64 result; // x0
  unsigned __int64 v3; // x20

  result = *((_QWORD *)a1 + 2);
  if ( result && *((_DWORD *)a1 + 1) && !*((_BYTE *)a1 + 28) )
  {
    if ( *a1 )
    {
      v3 = 0;
      while ( 1 )
      {
        result = *((_QWORD *)a1 + 2);
        if ( !*(_QWORD *)(result + 8 * v3) )
          break;
        _free_pages(*(_QWORD *)(result + 8 * v3++), *((unsigned int *)a1 + 6));
        if ( v3 >= *a1 )
        {
          result = *((_QWORD *)a1 + 2);
          break;
        }
      }
    }
    result = kfree(result);
  }
  *((_QWORD *)a1 + 2) = 0;
  *((_QWORD *)a1 + 3) = 0;
  *(_QWORD *)a1 = 0;
  *((_QWORD *)a1 + 1) = 0;
  return result;
}
