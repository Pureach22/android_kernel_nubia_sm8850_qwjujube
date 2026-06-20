__int64 init_module()
{
  unsigned int v0; // w0
  __int64 v1; // x0
  unsigned int v2; // w19
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x0
  __int64 v6; // x19
  unsigned __int64 v7; // x0
  __int64 v8; // x19
  __int64 i; // x19

  v0 = _cpuhp_setup_state(61, "block/zram:prepare", 0, zcomp_cpu_up_prepare, zcomp_cpu_dead, 1);
  if ( (v0 & 0x80000000) != 0 )
  {
    return v0;
  }
  else
  {
    v1 = class_register(&zram_control_class);
    if ( (_DWORD)v1 )
    {
      v2 = v1;
      printk(&unk_B240);
      _cpuhp_remove_state(61, 0);
    }
    else
    {
      zram_major = _register_blkdev(v1, "zram", 0);
      if ( zram_major <= 0 )
      {
        printk(&unk_B42D);
        class_unregister(&zram_control_class);
        _cpuhp_remove_state(61, 0);
        return (unsigned int)-16;
      }
      else
      {
        if ( num_devices )
        {
          while ( 1 )
          {
            mutex_lock(&zram_index_mutex);
            v2 = zram_add();
            mutex_unlock(&zram_index_mutex);
            if ( (v2 & 0x80000000) != 0 )
              break;
            if ( !--num_devices )
              goto LABEL_7;
          }
        }
        else
        {
LABEL_7:
          v3 = 0;
          v4 = 32;
          _ReadStatusReg(SP_EL0);
          do
          {
            v5 = _alloc_pages_noprof(3264, 0, 0, 0);
            if ( !v5 )
            {
              printk(&unk_B374);
              if ( v3 )
              {
                v6 = 40LL * (unsigned int)~(_DWORD)v3 + 32;
                do
                {
                  _free_pages(*(_QWORD *)((char *)comp_out_queue + v6), 0);
                  *(_QWORD *)((char *)comp_out_queue + v6) = 0;
                  v6 -= 40;
                }
                while ( v6 != -8 );
              }
              v2 = -12;
              goto LABEL_23;
            }
            --v3;
            *(_QWORD *)((char *)comp_out_queue + v4) = v5;
            v4 += 40;
          }
          while ( v3 != -128 );
          v7 = kthread_create_on_node(zram_qpace_comp, 0, 0xFFFFFFFFLL, "zram_comp");
          v8 = v7;
          if ( v7 <= 0xFFFFFFFFFFFFF000LL )
            wake_up_process(v7);
          comp_thread = v8;
          if ( v8 )
            return 0;
          for ( i = 5112; i != -8; i -= 40 )
          {
            _free_pages(*(_QWORD *)((char *)comp_out_queue + i), 0);
            *(_QWORD *)((char *)comp_out_queue + i) = 0;
          }
          v2 = 0;
        }
LABEL_23:
        destroy_devices();
      }
    }
  }
  return v2;
}
