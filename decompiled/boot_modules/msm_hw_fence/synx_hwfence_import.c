__int64 __fastcall synx_hwfence_import(unsigned int *a1, _DWORD *a2)
{
  __int64 v2; // x30
  unsigned __int64 v5; // x22
  _QWORD *v6; // x21
  __int64 v7; // x23
  unsigned int v8; // w8
  unsigned int v9; // w24
  unsigned int v10; // w0
  __int64 result; // x0
  unsigned int v12; // w21

  if ( a1
    && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL
    && *a1 - 1024 <= 0xBFF
    && a2
    && (unsigned __int64)a2 < 0xFFFFFFFFFFFFF001LL )
  {
    v5 = *((_QWORD *)a1 + 1);
    v6 = a2 + 2;
    if ( *a2 == 2 )
    {
      if ( v5 && v5 <= 0xFFFFFFFFFFFFF000LL && (unsigned __int64)v6 <= 0xFFFFFFFFFFFFF000LL && a2[4] )
      {
        v7 = v2;
        v8 = 0;
        while ( 1 )
        {
          v9 = v8;
          v10 = synx_hwfence_import_indv(v5, *v6 + 24LL * (int)v8);
          if ( v10 )
            break;
          v8 = v9 + 1;
          if ( v9 + 1 >= a2[4] )
            return 0;
        }
        v12 = v10;
        printk(&unk_2A5C9, "synx_hwfence_import_arr", 663, v7, v9);
      }
      else
      {
        v7 = v2;
        printk(&unk_215AA, "synx_hwfence_import_arr", 655, v2, *((_QWORD *)a1 + 1));
        v12 = -22;
      }
    }
    else
    {
      v7 = v2;
      result = synx_hwfence_import_indv(*((_QWORD *)a1 + 1), a2 + 2);
      if ( !(_DWORD)result )
        return result;
      v12 = result;
    }
    printk(&unk_23416, "synx_hwfence_import", 689, v7, *a1);
    return v12;
  }
  else
  {
    printk(&unk_26E16, "synx_hwfence_import", 678, v2, a1);
    return 4294967274LL;
  }
}
