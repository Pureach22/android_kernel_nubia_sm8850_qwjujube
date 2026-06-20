__int64 __fastcall synx_hwfence_signal_n(unsigned int *a1, _DWORD *a2)
{
  __int64 v2; // x30
  unsigned __int64 v5; // x4
  _QWORD *v6; // x21
  __int64 v7; // x22
  __int64 result; // x0
  unsigned int v9; // w21
  unsigned int v10; // w8
  unsigned int v11; // w23
  unsigned int v12; // w0

  if ( a1
    && (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL
    && *a1 - 1024 <= 0xBFF
    && a2
    && (unsigned __int64)a2 <= 0xFFFFFFFFFFFFF000LL
    && (v5 = *((_QWORD *)a1 + 1)) != 0 )
  {
    v6 = a2 + 2;
    if ( *a2 == 1 )
    {
      v7 = v2;
      result = synx_hwfence_signal_n_indv(a1, a2 + 2);
      if ( !(_DWORD)result )
        return result;
      v9 = result;
    }
    else if ( v5 <= 0xFFFFFFFFFFFFF000LL && (unsigned __int64)v6 <= 0xFFFFFFFFFFFFF000LL && a2[4] )
    {
      v7 = v2;
      v10 = 0;
      while ( 1 )
      {
        v11 = v10;
        v12 = synx_hwfence_signal_n_indv(a1, *v6 + 32LL * (int)v10);
        if ( v12 )
          break;
        v10 = v11 + 1;
        if ( v11 + 1 >= a2[4] )
          return 0;
      }
      v9 = v12;
      printk(&unk_2833C, "synx_hwfence_signal_n_arr", 414, v7, v11);
    }
    else
    {
      v7 = v2;
      printk(&unk_2A56E, "synx_hwfence_signal_n_arr", 406, v2, v5);
      v9 = -22;
    }
    printk(&unk_20DC7, "synx_hwfence_signal_n", 442, v7, *a1);
    return v9;
  }
  else
  {
    printk(&unk_27CE8, "synx_hwfence_signal_n", 431, v2, a1);
    return 4294967274LL;
  }
}
