__int64 __fastcall pmic_glink_debug_remove(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  __int64 v3; // x20
  __int64 v4; // x9
  __int64 v5; // x0
  unsigned int v6; // w8
  unsigned int i; // w20
  __int64 v8; // x9

  v1 = *(_QWORD *)(a1 + 168);
  if ( *(_DWORD *)(v1 + 400) )
  {
    v2 = 0;
    do
    {
      v3 = v2;
      v4 = *(_QWORD *)(*(_QWORD *)(v1 + 384) + 8LL * v2);
      if ( v4 )
      {
        spmi_controller_remove(*(_QWORD *)(v4 + 8));
        v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 384) + 8 * v3) + 8LL);
        if ( v5 )
          put_device(v5);
      }
      v2 = v3 + 1;
    }
    while ( (unsigned int)(v3 + 1) < *(_DWORD *)(v1 + 400) );
  }
  v6 = *(_DWORD *)(v1 + 404);
  if ( v6 )
  {
    for ( i = 0; i < v6; ++i )
    {
      v8 = *(_QWORD *)(*(_QWORD *)(v1 + 392) + 8LL * (int)i);
      if ( v8 )
      {
        i2c_del_adapter(v8 + 8);
        v6 = *(_DWORD *)(v1 + 404);
      }
    }
  }
  return pmic_glink_unregister_client(*(_QWORD *)v1);
}
