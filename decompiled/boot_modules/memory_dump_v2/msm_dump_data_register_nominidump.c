unsigned __int64 __fastcall msm_dump_data_register_nominidump(int a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 v3; // x9
  unsigned __int64 result; // x0
  unsigned int v5; // w8
  unsigned __int64 v6; // x9
  __int64 v7; // x10

  if ( qword_8DB0 )
  {
    v2 = -16128;
    while ( *(_DWORD *)(qword_8DB0 + v2 + 16136) != a1 )
    {
      v2 += 48;
      if ( !v2 )
        goto LABEL_12;
    }
    v3 = *(_QWORD *)(qword_8DB0 + v2 + 16176);
    if ( !v3 )
    {
LABEL_12:
      printk(&unk_85E0);
      return -22;
    }
    result = qword_8DB0 + v3 - memdump;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      if ( result && (v5 = *(_DWORD *)(result + 4), v5 <= 0x14F) )
      {
        v6 = result + 48LL * v5;
        *(_DWORD *)(v6 + 8) = *(_DWORD *)a2;
        *(_DWORD *)(v6 + 44) = 0;
        v7 = *(_QWORD *)(a2 + 40);
        *(_DWORD *)(result + 4) = v5 + 1;
        *(_QWORD *)(v6 + 48) = v7;
        return 0;
      }
      else
      {
        return 4294967274LL;
      }
    }
  }
  else
  {
    printk(&unk_848C);
    return -22;
  }
  return result;
}
