__int64 sub_95DA4()
{
  __int64 v0; // x13
  unsigned int v1; // w21

  atomic_store(v1, (unsigned int *)(v0 - 220));
  return dp_connector_atomic_check();
}
