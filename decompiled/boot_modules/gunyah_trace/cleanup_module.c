__int64 cleanup_module()
{
  debugfs_remove(qword_7E18);
  free_irq((unsigned int)dword_7DE0, &gunyah_trace_data);
  irq_dispose_mapping((unsigned int)dword_7DE0);
  kfree(qword_7E38);
  return iounmap(gunyah_trace_data);
}
