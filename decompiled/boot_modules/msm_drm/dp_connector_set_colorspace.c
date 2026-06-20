__int64 __fastcall dp_connector_set_colorspace(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  __int64 v4; // x9
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x10
  __int64 v6; // x2

  result = 4294967274LL;
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 2768);
    if ( v4 )
    {
      v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a2 + 184);
      v6 = *(unsigned int *)(*(_QWORD *)(a1 + 2512) + 128LL);
      if ( *((_DWORD *)v5 - 1) != -1716353830 )
        __break(0x822Au);
      return v5(a2, v4, v6);
    }
    else
    {
      printk(&unk_234497, a2);
      return 4294967274LL;
    }
  }
  return result;
}
