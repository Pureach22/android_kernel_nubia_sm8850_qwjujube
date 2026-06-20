_DWORD *__fastcall qcom_smem_partition_header(_QWORD *a1, _DWORD *a2, unsigned __int16 a3, unsigned __int16 a4)
{
  _DWORD *result; // x0
  unsigned int v9; // w8

  result = (_DWORD *)devm_ioremap_wc(*a1, (unsigned int)(*a2 + *((_DWORD *)a1 + 220)), (unsigned int)a2[1]);
  if ( result )
  {
    if ( *result == 1414680612 )
    {
      if ( *((unsigned __int16 *)result + 2) == a3 )
      {
        if ( *((unsigned __int16 *)result + 3) == a4 )
        {
          v9 = result[2];
          if ( v9 == a2[1] )
          {
            if ( result[3] <= v9 )
              return result;
            dev_err(*a1, "bad partition free uncached (%u > %u)\n");
          }
          else
          {
            dev_err(*a1, "bad partition size (%u != %u)\n");
          }
        }
        else
        {
          dev_err(*a1, "bad host1 (%hu != %hu)\n");
        }
      }
      else
      {
        dev_err(*a1, "bad host0 (%hu != %hu)\n");
      }
    }
    else
    {
      dev_err(*a1, "bad partition magic %4ph\n", result);
    }
    return nullptr;
  }
  return result;
}
