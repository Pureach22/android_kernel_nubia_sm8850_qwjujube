__int64 __fastcall hdcp2_update_app_data_smcinvoke(__int64 a1, __int64 a2)
{
  if ( a1 && a2 )
  {
    *(_QWORD *)(a2 + 8) = *(_QWORD *)(a1 + 8);
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(a1 + 16);
    *(_QWORD *)(a2 + 24) = *(_QWORD *)(a1 + 24);
    *(_DWORD *)(a2 + 32) = *(_DWORD *)(a1 + 32);
    *(_DWORD *)a2 = *(_DWORD *)a1;
    *(_BYTE *)(a2 + 4) = *(_BYTE *)(a1 + 4);
    return 0;
  }
  else
  {
    printk(&unk_C11E);
    return 4294967274LL;
  }
}
