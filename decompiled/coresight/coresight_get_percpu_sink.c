__int64 __fastcall coresight_get_percpu_sink(unsigned int a1)
{
  if ( a1 >= 0x20 )
  {
    __break(0x5512u);
    JUMPOUT(0x595CC);
  }
  return *(_QWORD *)((char *)&csdev_sink + _per_cpu_offset[a1]);
}
