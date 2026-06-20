void rmnet_offload_engine_exit()
{
  __int64 i; // x8
  _QWORD *v1; // x10
  _QWORD *v2; // x11
  _QWORD *v3; // x12

  for ( i = 0; i != 32; ++i )
  {
    v1 = (_QWORD *)rmnet_offload_flow_table[i];
    if ( v1 )
    {
      do
      {
        v2 = (_QWORD *)*v1;
        v3 = (_QWORD *)v1[1];
        if ( v3 )
        {
          *v3 = v2;
          if ( v2 )
            v2[1] = v3;
          *v1 = 0;
          v1[1] = 0;
        }
        v1 = v2;
      }
      while ( v2 );
    }
  }
}
