__int64 rmnet_offload_engine_init()
{
  __int64 v0; // x0
  __int64 v1; // x8
  _QWORD *v2; // x9

  v0 = rmnet_offload_state_get();
  v1 = 50;
  v2 = (_QWORD *)(v0 + 120);
  do
  {
    --v1;
    *(v2 - 1) = v2 - 1;
    *v2 = v2 - 1;
    *(v2 - 3) = 0;
    *(v2 - 2) = 0;
    v2 += 13;
  }
  while ( v1 );
  return 0;
}
