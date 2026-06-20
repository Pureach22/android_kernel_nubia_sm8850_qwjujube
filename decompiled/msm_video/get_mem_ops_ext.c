__int64 *get_mem_ops_ext()
{
  __int64 (__fastcall **mem_ops)(); // x0
  __int64 v1; // x10
  __int64 v2; // x11
  __int64 v3; // x12
  __int64 v4; // x13
  __int64 v5; // x14
  __int64 v6; // x15
  __int64 v7; // x13
  __int64 v8; // x16
  __int64 v9; // x17
  __int64 v10; // x0
  __int64 v11; // x9

  mem_ops = get_mem_ops();
  v1 = (__int64)mem_ops[2];
  v2 = (__int64)mem_ops[4];
  v3 = (__int64)mem_ops[5];
  qword_9E9C0 = (__int64)mem_ops[3];
  v4 = (__int64)mem_ops[8];
  v5 = (__int64)mem_ops[6];
  v6 = (__int64)mem_ops[9];
  qword_9E9E0 = (__int64)mem_ops[7];
  qword_9E9E8 = v4;
  v7 = (__int64)mem_ops[10];
  v8 = (__int64)mem_ops[12];
  v9 = (__int64)mem_ops[13];
  qword_9EA00 = (__int64)mem_ops[11];
  v11 = (__int64)*mem_ops;
  v10 = (__int64)mem_ops[1];
  qword_9E9C8 = v2;
  qword_9E9D0 = v3;
  qword_9EA08 = v8;
  qword_9EA10 = v9;
  qword_9E9B8 = v1;
  qword_9E9C0 = (__int64)msm_vidc_dma_buf_attach_ext;
  get_mem_ops_ext_mem_ops_ext = v11;
  qword_9E9B0 = v10;
  qword_9E9D8 = v5;
  qword_9E9E0 = (__int64)msm_vidc_memory_alloc_map_ext;
  qword_9E9E8 = (__int64)msm_vidc_memory_unmap_free_ext;
  qword_9E9F0 = v6;
  qword_9E9F8 = v7;
  qword_9EA00 = (__int64)msm_vidc_buffer_region_ext;
  return &get_mem_ops_ext_mem_ops_ext;
}
